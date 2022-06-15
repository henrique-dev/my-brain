## Rails, Puma, RSpec, Nginx e PostgreSQL
### Observações
- Substituir 'nome_da_aplicacao' pelo nome da sua aplicacao
- Substituir a porta 8020 pela porta que deseja usar na aplicação
### Criando o repositorio e a aplicação
```
mkdir nome_aplicacao
cd nome_aplicacao
rails new nome_aplicacao -d postgresql --skip-bundle --skip-test --skip-system-test
rm -rf nome_aplicacao/.git
rm -rf nome_aplicacao/.gitignore
git init .
git add .
git commit -m "First commit"
```
A estrutura do projeto devera ser a seguinte:
- nome_aplicacao (raiz)
  - nome_aplicacao (aplicação rails)

### Adicionar as gems necessárias

Adicione as seguintes gems na aplicação.
> nome_aplicacao/Gemfile

```ruby
# Pg is the Ruby interface to the PostgreSQL RDBMS. It works with PostgreSQL 9.3 and later.
gem 'pg', '~> 1.3', '>= 1.3.5' # se ainda não estiver

# Redis for Ruby on Rails
gem 'redis-rails', '~> 5.0', '>= 5.0.2'

# Simple, efficient background processing for Ruby.
gem 'sidekiq', '~> 6.5', '>= 6.5.1'

# Great Ruby debugging companion: pretty print Ruby objects to visualize their structure. Supports custom object formatting via plugins
gem 'awesome_print', '~> 1.9', '>= 1.9.2' # opcional

# Use Pry as your rails console
gem 'pry-rails', '~> 0.3.9' # opcional

# Slim is a template language whose goal is reduce the syntax to the essential parts without becoming cryptic.
gem 'slim', '~> 4.1' # opcional

# Provides the generator settings required for Rails to use Slim
gem 'slim-rails', '~> 3.5', '>= 3.5.1' # opcional

group :development, :test do
  # RuboCop is a Ruby code style checking and code formatting tool. It aims to enforce the community-driven Ruby Style Guide.
  gem 'rubocop', '~> 1.30', '>= 1.30.1'
  
  # BDD for Ruby
  gem 'rspec', '~> 3.11'
  
  # gem 'rspec-rails', '~> 5.1', '>= 5.1.2'
  gem 'rspec-rails', '~> 5.1'
  
  # Set of matchers and helpers to allow you test your APIs responses like a pro.
  gem 'rspec-json_expectations', '~> 2.2'
end

group :test do
  # Strategies for cleaning databases using ActiveRecord. Can be used to ensure a clean state for testing.
  gem 'database_cleaner-active_record', '~> 2.0', '>= 2.0.1'
end
```
Após isso execute
```
bundle install
```

### Inicializar o Rspec
```
rails g rspec:install
```

### Configurar a aplicação pra usar o Slim como gerador de templates e usar o Rspec pra gerar os testes
Adicione as seguintes linhas:
>nome_aplicacao/config/application.rb
```ruby
# Since we're using Redis for Sidekiq, we might as well use Redis to back
# our cache store. This keeps our application stateless as well.
config.cache_store = :redis_store, ENV['CACHE_URL'],
                     { namespace: 'atena::cache' }

# If you've never dealt with background workers before, this is the Rails
# way to use them through Active Job. We just need to tell it to use Sidekiq.
config.active_job.queue_adapter = :sidekiq

# Don't generate system test files.
config.generators.system_tests = nil

# descomentar abaixo se for usar o slim como gerador de templates
# config.generators do |g|
#   g.template_engine :slim
# end
```

### Testando a aplicação (opcional)
```
rails s -b 0.0.0.0
```

### Configurando a aplicação pra trabalhar com Redis e Postgresql
Substitua a configuração atual dos arquivos, substituindo nome_aplicacao pelo nome da sua aplicação, pelas seguintes:
> nome_aplicacao/config/database.yml
```yml
default: &default
  adapter: postgresql
  encoding: unicode
  host: postgresdb
  username: postgres
  password: password
  pool: 5

development:
  <<: *default
  database: nome_aplicacao_development


test:
  <<: *default
  database: nome_aplicacao_test

production:
  <<: *default
  database: nome_aplicacao_production
  username: nome_aplicacao
  password: <%= ENV["NOME_APLICACAO_DATABASE_PASSWORD"] %>
```

> nome_aplicacao/config/cable.yml
```yml
development:
  adapter: redis
  url: <%= ENV.fetch("REDIS_URL") { "redis://redis:6379/1" } %>
  channel_prefix: nome_aplicacao_production

test:
  adapter: test

production:
  adapter: redis
  url: <%= ENV.fetch("REDIS_URL") { "redis://redis:6379/1" } %>
  channel_prefix: nome_aplicacao_production
```

### Criação do arquivo .env
Crie dois arquivos: .env e .env-example
Cole o seguinte conteúdo em ambos:
> .env
>
> .env-example
```
# Docker user and group ids
# On linux these should match your ids
USER_ID=1000
GROUP_ID=1000

# You would typically use rake secret to generate a secure token. It is
# critical that you keep this value private in production.
USER_GITHUB=
TOKEN_GITHUB=

# Unicorn is more than capable of spawning multiple workers, and in production
# you would want to increase this value but in development you should keep it
# set to 1.
#
# It becomes difficult to properly debug code if there's multiple copies of
# your application running via workers and/or threads.
WORKER_PROCESSES=1

# This will be the address and port that Unicorn binds to. The only real
# reason you would ever change this is if you have another service running
# that must be on port 8010.
LISTEN_ON=0.0.0.0:8010

# This is how we'll connect to PostgreSQL. It's good practice to keep the
# username lined up with your application's name but it's not necessary.
#
# Since we're dealing with development mode, it's ok to have a weak password
# such as yourpassword but in production you'll definitely want a better one.
#
# Eventually we'll be running everything in Docker containers, and you can set
# the host to be equal to postgres thanks to how Docker allows you to link
# containers.
#
# Everything else is standard Rails configuration for a PostgreSQL database.
DATABASE_HOST=postgres
DATABASE_PORT=5432

# Both of these values are using the same Redis address but in a real
# production environment you may want to separate Sidekiq to its own instance,
# which is why they are separated here.
#
# We'll be using the same Docker link trick for Redis which is how we can
# reference the Redis hostname as redis.
CACHE_URL=redis://redis:6379/0
JOB_WORKER_URL=redis://redis:6379/0
```

### Criação do arquivo de configuração do sidekiq
Crie e cole o seguinte conteúdo no arquivo:
> nome_aplicacao/config/initializers/sidekiq.rb
```ruby
sidekiq_config = { url: ENV['JOB_WORKER_URL'] }

Sidekiq.configure_server do |config|
  config.redis = sidekiq_config
end

Sidekiq.configure_client do |config|
  config.redis = sidekiq_config
end
```

### Criação do arquivo de configuração do puma
Modifique a configuração do puma para aceitar requisições na seguinte porta:
> nome_aplicacao/config/puma.rb
```ruby
...
port ENV.fetch("PORT") { 8010 }
...
```

### .gitignore e .dockerignore
Adicione as seguintes linhas no arquivo
>.gitignore
```
# See https://help.github.com/articles/ignoring-files for more about ignoring files.
#
# If you find yourself ignoring temporary files generated by your text editor
# or operating system, you probably want to add a global ignore instead:
#   git config --global core.excludesfile '~/.gitignore_global'

# Ignore bundler config.
nome_aplicacao/.bundle

# Ignore all logfiles and tempfiles.
nome_aplicacao/log/*
nome_aplicacao/tmp/*
!log/.keep
!tmp/.keep

# Ignore pidfiles, but keep the directory.
nome_aplicacao/tmp/pids/*
!tmp/pids/
!tmp/pids/.keep


nome_aplicacao/public/assets
nome_aplicacao/.byebug_history

# Ignore master key for decrypting credentials and more.
nome_aplicacao/config/master.key

nome_aplicacao/public/packs
nome_aplicacao/public/packs-test
nome_aplicacao/node_modules
nome_aplicacao/yarn-error.log
nome_aplicacao/yarn-debug.log*
nome_aplicacao/.yarn-integrity
```
>.dockerignore
```
.git
.gitignore
.env
nome_aplicacao/.bin
nome_aplicacao/.bundleignore
nome_aplicacao/.bundle
nome_aplicacao/.byebug_history
nome_aplicacao/.rspec
nome_aplicacao/tmp
nome_aplicacao/log
nome_aplicacao/test
nome_aplicacao/config/deploy
nome_aplicacao/public/packs
nome_aplicacao/public/packs-test
nome_aplicacao/node_modules
nome_aplicacao/yarn-error.log
nome_aplicacao/coverage/
```

### Criando os arquivos Dockerfile
Seu Dockerfile especifica o que será incluído no contêiner do seu aplicativo quando ele estiver criado. Usar um Dockerfile permite que você defina seu ambiente de contêiner e evite discrepâncias com as dependências ou versões de tempo de execução.

Crie e cole o seguinte conteúdo nos seguintes arquivos:
> Dockerfile
```Dockerfile
# Dockerfile development version
FROM ruby:3.1.0 AS nome_aplicacao-development

ARG USER_ID
ARG GROUP_ID
ARG TOKEN_GITHUB
ARG USER_GITHUB

RUN addgroup --gid $GROUP_ID user
RUN adduser --disabled-password --gecos '' --uid $USER_ID --gid $GROUP_ID user

RUN curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg -o /root/yarn-pubkey.gpg && apt-key add /root/yarn-pubkey.gpg
RUN echo "deb https://dl.yarnpkg.com/debian/ stable main" > /etc/apt/sources.list.d/yarn.list
RUN apt-get update && apt-get install -y --no-install-recommends nodejs yarn redis

ENV INSTALL_PATH /opt/app
RUN mkdir -p $INSTALL_PATH

WORKDIR $INSTALL_PATH
COPY nome_aplicacao/ .
RUN rm -rf node_modules vendor
RUN gem install rails bundler
RUN bundle install
RUN chown -R user:user /opt/app

USER $USER_ID
CMD ["bundle", "exec", "puma", "-C", "config/puma.rb"]
```
> Dockerfile.nginx
```Dockerfile
FROM nginx:latest
RUN apt-get update -qq && apt-get -y install apache2-utils
COPY reverse-proxy.conf /etc/nginx/conf.d/reverse-proxy.conf
RUN mkdir -p /opt/app/log
EXPOSE 8020
STOPSIGNAL SIGTERM
CMD ["nginx", "-g", "daemon off;"]
```

### Criando o arquivo de configuração do Nginx
>reverse-proxy.conf
```conf
upstream app {
  server hera:8010 fail_timeout=0;
}
server {
  listen 8020;
  server_name localhost;
  # ~2 seconds is often enough for most folks to parse HTML/CSS and
  # retrieve needed images/icons/frames, connections are cheap in
  # nginx so increasing this is generally safe...
  keepalive_timeout 5;
  # path for static files
  root /opt/app/public;
  access_log /opt/app/log/nginx.access.log;
  error_log /opt/app/log/nginx.error.log info;
  # this rewrites all the requests to the maintenance.html
  # page if it exists in the doc root. This is for capistrano's
  # disable web task
  if (-f $document_root/maintenance.html) {
    rewrite  ^(.*)$  /maintenance.html last;
    break;
  }
  location / {
    proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
    proxy_set_header Host $http_host;
    proxy_redirect off;
    # If the file exists as a static file serve it directly without
    # running all the other rewrite tests on it
    if (-f $request_filename) {
      break;
    }
    # check for index.html for directory index
    # if it's there on the filesystem then rewrite
    # the url to add /index.html to the end of it
    # and then break to send it to the next config rules.
    if (-f $request_filename/index.html) {
      rewrite (.*) $1/index.html break;
    }
    # this is the meat of the rack page caching config
    # it adds .html to the end of the url and then checks
    # the filesystem for that file. If it exists, then we
    # rewrite the url to have explicit .html on the end
    # and then send it on its way to the next config rule.
    # if there is no file on the fs then it sets all the
    # necessary headers and proxies to our upstream pumas
    if (-f $request_filename.html) {
      rewrite (.*) $1.html break;
    }
    if (!-f $request_filename) {
      proxy_pass http://app;
      break;
    }
  }
  # Now this supposedly should work as it gets the filenames with querystrings that Rails provides.
  # BUT there's a chance it could break the ajax calls.
  location ~* \.(ico|css|gif|jpe?g|png|js)(\?[0-9]+)?$ {
     expires max;
     break;
  }
  # Error pages
  # error_page 500 502 503 504 /500.html;
  location = /500.html {
    root /app/current/public;
  }
}
```

### Criando o arquivo docker-compose.yml
>docker-compose.yml
```yml
version: '3.7'
services:
  postgresdb:
    image: postgres
    restart: always
    ports:
      - '5432'
    volumes:
      - postgresdb_data_container:/data/db
    networks:
      - backend-network
    environment:
      POSTGRES_PASSWORD: password
  redis:
    image: redis:5.0.7
    ports:
      - '6379'
    networks:
      - backend-network
    volumes:
      - redis_data_container:/var/lib/redis/data
  nome_aplicacao:
    build:
      context: .
      args:
        USER_ID: "${USER_ID:-1000}"
        GROUP_ID: "${GROUP_ID:-1000}"
        TOKEN_GITHUB: "${TOKEN_GITHUB:-1000}"
        USER_GITHUB: "${USER_GITHUB:-1000}"
    volumes:
      - ./nome_aplicacao:/opt/app
    ports:
      - '8010'
    depends_on:
      - redis
      - postgresdb
      - sidekiq
    env_file:
      - .env
    networks:
      - backend-network
  sidekiq:
    build:
      context: .
      args:
        USER_ID: "${USER_ID:-1000}"
        GROUP_ID: "${GROUP_ID:-1000}"
        TOKEN_GITHUB: "${TOKEN_GITHUB:-1000}"
        USER_GITHUB: "${USER_GITHUB:-1000}"
    volumes:
      - ./nome_aplicacao:/opt/app
    command: bundle exec sidekiq
    depends_on:
      - redis
      - postgresdb
    env_file:
      - .env
    networks:
      - backend-network
  nginx:
    build:
      context: .
      dockerfile: ./Dockerfile.nginx
    networks:
      - backend-network
    ports:
      - '8020:8020'
    depends_on:
      - nome_aplicacao

networks:
  backend-network:
    driver: bridge

volumes:
  postgresdb_data_container:
  redis_data_container:
```
### Colocando tudo pra funcionar
```
docker-compose build
docker-compose up
docker-compose exec nome_aplicacao rails db:create
docker-compose exec nome_aplicacao rails db:migrate
```

