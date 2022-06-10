## Conteinerizando um aplicativo Ruby on Rails para desenvolvimento com o Docker Compose
Se você estiver desenvolvendo ativamente um aplicativo, usar o Docker pode simplificar seu fluxo de trabalho e o processo de implantação do seu aplicativo para produção. Trabalhar com contêineres no desenvolvimento oferece os seguintes benefícios:

- Os ambientes são consistentes, o que significa que você pode escolher as linguagens e dependências que quiser para seu projeto sem se preocupar com conflitos de sistema.
- Os ambientes são isolados, tornando mais fácil a resolução de problemas e a adição de novos membros de equipe.
- Os ambientes são portáteis, permitindo que você empacote e compartilhe seu código com outros.

### Pré-requisitos

- Debian 10
- Docker
- Docker Compose

### Observações
Versões utilizadas:
Ruby: 3.1.0
Rails: 7.0.3

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
gem 'pg', '~> 1.3', '>= 1.3.4' # se ainda não estiver
gem 'redis-rails', '~> 5.0', '>= 5.0.1'
gem 'sidekiq', '~> 4.1', '>= 4.1.2'
gem 'awesome_print', '~> 1.8' # opcional
gem 'pry-rails', '~> 0.3.3' # opcional
gem 'slim', '~> 3.0', '>= 3.0.6' # opcional
gem 'slim-rails', '~> 3.1', '>= 3.1.1' # opcional

group :development, :test do
  gem 'rubocop', '~> 1.25', '>= 1.25.1'
  gem 'rspec', '~> 3.11'
  gem 'rspec-rails', '~> 5.1'
  gem 'rspec-json_expectations', '~> 2.2'
end

group :test do
  gem 'database_cleaner-active_record'
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
/nome_aplicacao/.bundle

# Ignore all logfiles and tempfiles.
/nome_aplicacao/log/*
/nome_aplicacao/tmp/*
!/log/.keep
!/tmp/.keep

# Ignore pidfiles, but keep the directory.
/nome_aplicacao/tmp/pids/*
!/tmp/pids/
!/tmp/pids/.keep


/nome_aplicacao/public/assets
/nome_aplicacao/.byebug_history

# Ignore master key for decrypting credentials and more.
/nome_aplicacao/config/master.key

/nome_aplicacao/public/packs
/nome_aplicacao/public/packs-test
/nome_aplicacao/node_modules
/nome_aplicacao/yarn-error.log
/nome_aplicacao/yarn-debug.log*
/nome_aplicacao/.yarn-integrity
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
COPY reverse-proxy.conf /etc/nginx/conf.d/reverse-proxy.conf
EXPOSE 8020
STOPSIGNAL SIGTERM
CMD ["nginx", "-g", "daemon off;"]
```

### Criando o arquivo de configuração do Nginx
>reverse-proxy.conf
```conf
# reverse-proxy.conf
upstream app {
    server nome_aplicacao:8010 fail_timeout=0;
}

server {
    listen 8020;
    server_name localhost;

    location / {
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto $scheme;
        proxy_set_header Host $http_host;
        proxy_redirect off;
    }

    location /cable {
        proxy_pass         http://app;
        proxy_http_version 1.1;
        proxy_set_header   Upgrade $http_upgrade;
        proxy_set_header   Connection "upgrade";
        proxy_set_header   Host $http_host;
        break;
    }

    error_page 500 502 503 504 /500;
    error_page 404 /404;
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
docker-compose run nome_aplicacao rails db:create
docker-compose up
```


## Rails e MongoDB
### Criando o repositorio e a aplicação
```
mkdir nome_aplicacao
cd nome_aplicacao
rails new nome_aplicacao --skip-bundle --skip-active-record --skip-test --skip-system-test
rm -rf nome_aplicacao/.git
rm -rf nome_aplicacao/.gitignore
git init .
git add .
git commit -m "First commit"
```
A estrutura do projeto devera ser a seguinte:
- nome_aplicacao (raiz)
  - nome_aplicacao (aplicação rails)

Certifique-se de que a versão do ruby é a 3.0.2
> nome_aplicacao/.ruby-version
```ruby
3.0.2
```
> nome_aplicacao/Gemfile
```ruby
...
ruby "3.0.2"
...
```

### Remove as gems desnecessárias
> nome_aplicacao/Gemfile

```ruby
gem "puma", "~> x.y"
```

### Adicionar as gems necessárias

Adicione as seguintes gems na aplicação.
> nome_aplicacao/Gemfile

```ruby
gem 'unicorn', '~> 6.1'
gem 'unicorn-rails', '~> 2.2', '>= 2.2.1'
gem 'webpacker', '~> 5.4', '>= 5.4.3'
gem 'mongoid', '~> 7.3.3'
gem 'sidekiq-batch', '~> 0.1.3'
gem 'redis-rails', '~> 5.0', '>= 5.0.2'
gem 'awesome_print', '~> 1.8'
gem 'pry-rails', '~> 0.3.3'
gem 'slim', '~> 3.0', '>= 3.0.6'
gem 'slim-rails', '~> 3.1', '>= 3.1.1'

group :development, :test do
  gem 'rubocop', '~> 1.25', '>= 1.25.1'
  gem 'rspec', '~> 3.11'
  gem 'rspec-rails', '~> 5.1'
  gem 'rspec-json_expectations', '~> 2.2'
end

group :test do
  gem 'database_cleaner-mongoid'
end
```
Após isso execute
```
bundle install
```

### Gerar o arquivo de configuração Mongoid
```
rails g mongoid:config
```

### Inicializar o webpacker e Rspec
```
rails webpacker:install
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

config.generators do |g|
  g.template_engine :slim
end
```
### Configurar o Rspec com o DatabaseCleaner
Adicione as seguintes linhas:
>nome_aplicacao/spec/spec_helper.rb
```ruby
RSpec.configure do |config|
  ...
  config.before(:suite) do
    DatabaseCleaner[:mongoid, db: :default].strategy = :deletion
    # for multiples databases
    DatabaseCleaner[:mongoid, db: :custom].strategy = :deletion
  end

  config.before(:each) do
    DatabaseCleaner.start
  end

  config.after(:each) do
    DatabaseCleaner.clean
  end
  ...
end
```

### Testando a aplicação (opcional)
```
rails s -b 0.0.0.0
```

### Excluindo arquivos desnecessários
Exclua do projeto os seguites arquivos:
> nome_aplicacao/config/puma.rb

### Configurando a aplicação pra trabalhar com Mongo e Redis
Substitua a configuração atual dos arquivos, substituindo nome_aplicacao pelo nome da sua aplicação, pelas seguintes:
> nome_aplicacao/config/mongoid.yml
```yml
production:
  clients:
    default:
      database: nome_aplicacao_production
      hosts:
        - <%= ENV.fetch('DATABASE_URL') { 'localhost:27017' } %>
      options:
        max_pool_size: 10
  options:
    raise_not_found_error: false
development:
  clients:
    default:
      database: nome_aplicacao_development
      hosts:
        - <%= ENV.fetch('DATABASE_URL') { 'localhost:27017' } %>
      options:
        max_pool_size: 10
  options:
    raise_not_found_error: false
staging:
  clients:
    default:
      database: nome_aplicacao_staging
      hosts:
        - <%= ENV.fetch('DATABASE_URL') { 'localhost:27017' } %>
      options:
        write:
          w: 1
        max_pool_size: 10
  options:
    raise_not_found_error: false
test:
  clients:
    default:
      database: nome_aplicacao_test
      hosts:
        - <%= ENV.fetch('DATABASE_URL') { 'localhost:27017' } %>
      options:
        read:
          mode: :primary
        max_pool_size: 10
  options:
    raise_not_found_error: false
```
Essas modificações nas configurações padrão do banco de dados nos permitirão definir as informações do nosso banco de dados dinamicamente usando variáveis de ambiente definidas nos arquivos .env, as quais não serão aplicadas no controle de versão.

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
DATABASE_URL=mongodb:27017

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

### Criação do arquivo de configuração do unicorn
Crie e cole o seguinte conteúdo no arquivo:
> nome_aplicacao/config/unicorn.rb
```ruby
# Heavily inspired by GitLab:
# https://github.com/gitlabhq/gitlabhq/blob/master/config/unicorn.rb.example

# Go with at least 1 per CPU core, a higher amount will usually help for fast
# responses such as reading from a cache.
worker_processes (ENV.fetch('WORKER_PROCESSES') { '1' }).to_i

# Listen on a tcp port or unix socket.
listen ENV.fetch('LISTEN_ON') { '0.0.0.0:8010' }

# Use a shorter timeout instead of the 60s default. If you are handling large
# uploads you may want to increase this.
timeout 30

# Combine Ruby 2.0.0dev or REE with "preload_app true" for memory savings:
# http://rubyenterpriseedition.com/faq.html#adapt_apps_for_cow
preload_app true
GC.respond_to?(:copy_on_write_friendly=) && GC.copy_on_write_friendly = true

# Enable this flag to have unicorn test client connections by writing the
# beginning of the HTTP headers before calling the application. This
# prevents calling the application for connections that have disconnected
# while queued. This is only guaranteed to detect clients on the same
# host unicorn runs on, and unlikely to detect disconnects even on a
# fast LAN.
check_client_connection false

before_fork do |server, worker|
  # Don't bother having the master process hang onto older connections.
  defined?(ActiveRecord::Base) && ActiveRecord::Base.connection.disconnect!

  # The following is only recommended for memory/DB-constrained
  # installations. It is not needed if your system can house
  # twice as many worker_processes as you have configured.
  #
  # This allows a new master process to incrementally
  # phase out the old master process with SIGTTOU to avoid a
  # thundering herd (especially in the "preload_app false" case)
  # when doing a transparent upgrade. The last worker spawned
  # will then kill off the old master process with a SIGQUIT.
  old_pid = "#{server.config[:pid]}.oldbin"
  if old_pid != server.pid
    begin
      sig = (worker.nr + 1) >= server.worker_processes ? :QUIT : :TTOU
      Process.kill(sig, File.read(old_pid).to_i)
    rescue Errno::ENOENT, Errno::ESRCH
    end
  end

  # Throttle the master from forking too quickly by sleeping. Due
  # to the implementation of standard Unix signal handlers, this
  # helps (but does not completely) prevent identical, repeated signals
  # from being lost when the receiving process is busy.
  # sleep 1
end

after_fork do |server, worker|
  # Per-process listener ports for debugging, admin, migrations, etc..
  # addr = "127.0.0.1:#{9293 + worker.nr}"
  # server.listen(addr, tries: -1, delay: 5, tcp_nopush: true)

  defined?(ActiveRecord::Base) && ActiveRecord::Base.establish_connection

  # If preload_app is true, then you may also want to check and
  # restart any other shared sockets/descriptors such as Memcached,
  # and Redis. TokyoCabinet file handles are safe to reuse
  # between any number of forked children (assuming your kernel
  # correctly implements pread()/pwrite() system calls).
end
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
/nome_aplicacao/.bundle

# Ignore all logfiles and tempfiles.
/nome_aplicacao/log/*
/nome_aplicacao/tmp/*
!/log/.keep
!/tmp/.keep

# Ignore pidfiles, but keep the directory.
/nome_aplicacao/tmp/pids/*
!/tmp/pids/
!/tmp/pids/.keep


/nome_aplicacao/public/assets
/nome_aplicacao/.byebug_history

# Ignore master key for decrypting credentials and more.
/nome_aplicacao/config/master.key

/nome_aplicacao/public/packs
/nome_aplicacao/public/packs-test
/nome_aplicacao/node_modules
/nome_aplicacao/yarn-error.log
/nome_aplicacao/yarn-debug.log*
/nome_aplicacao/.yarn-integrity
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
FROM ruby:3.0.2 AS nome_aplicacao-development

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
RUN gem install rails bundler unicorn
RUN bundle install
RUN chown -R user:user /opt/app

USER $USER_ID
CMD bundle exec unicorn -c config/unicorn.rb
```
> Dockerfile.nginx
```Dockerfile
FROM nginx:latest
COPY reverse-proxy.conf /etc/nginx/conf.d/reverse-proxy.conf
EXPOSE 8020
STOPSIGNAL SIGTERM
CMD ["nginx", "-g", "daemon off;"]
```

### Criando o arquivo de configuração do Nginx
>reverse-proxy.conf
```conf
# reverse-proxy.conf
upstream app {
    server nome_aplicacao:8010 fail_timeout=0;
}

server {
    listen 8020;
    server_name localhost;

    location / {
        proxy_pass http://app;
        proxy_set_header Host $host;
        proxy_set_header X-Forwarded-For $proxy_add_x_forwarded_for;
        proxy_set_header X-Forwarded-Proto $scheme;
        proxy_set_header X-Forwarded-Port $server_port;
        proxy_set_header X-Forwarded-Host $host;
    }

    location /cable {
        proxy_pass         http://app;
        proxy_http_version 1.1;
        proxy_set_header   Upgrade $http_upgrade;
        proxy_set_header   Connection "upgrade";
        proxy_set_header   Host $http_host;
        break;
    }
}
```

### Criando o arquivo docker-compose.yml
>docker-compose.yml
```yml
version: '3.7'
services:
  mongodb:
    image: mongo
    restart: always
    ports:
      - '27017'
    volumes:
      - mongodb_data_container:/data/db
    networks:
      - backend-network
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
      - mongodb
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
      - mongodb
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
  mongodb_data_container:
  redis_data_container:
```

### Colocando tudo pra funcionar
```
docker-compose build
docker-compose up
```

