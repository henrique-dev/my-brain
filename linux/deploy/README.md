# Fazendo o deploy de uma Aplicação Web no Amazon EC2

## Aplicação Rails

### 1. Criando a aplicação Rails
O primeiro passo é [criar nossa aplicação](../docker/rails-puma-rspec-nginx-postgresql.md).

### 2. Criar uma instancia EC2
Depois temos que criar uma [instancia EC2](https://us-east-1.console.aws.amazon.com/ec2/v2/home?region=us-east-1#Instances:v=3). Para isso vá em *Launch Instances*.

- Name and tags:

      Coloque uma descrição/tag para sua instancia.
- Application and OS Images (Amazon Machine Image):

      Escolha uma imagem para a instancia. Nesse caso devemos utilizar o Debian
- Instance type:

      Escolha a que melhor se encaixa no seu projeto.
- Key pair:

      É necessário criar os pares de chaves para conseguirmos acessar nossa instancia via ssh local. Depois de criar não esqueça de guardar o 'nome-do-arquivo'.pem pois precisaremos dele.
- Network settings

      Aqui devemos criar um grupo de segurança permitindo o tráfego HTTP e SSH.
- Configure storage:

      Escolhemos o tamanho e tipo de armazenamento que iremos querer para a instancia.

Após configurarmos tudo, podemos prosseguir com a criação da instancia.

Depois de criada, podemos clicar na nossa instancia para vermos mais detalhes. Através do *Public IPv4 address* podemos acessar nossa aplicação. Se fizermos isso agora veremos apenas um erro de *ERR_CONNECTION_TIMED_OUT* porque não temos nada configurado ainda.

### 3. Configurando a instancia

Agora vamos configurar nossa instancia. Para isso vamos primeiro em *Connect* e selecionamos a aba *SSH Client*. Lá teremos detalhes de como conectar à nossa instancia. Para isso, utilizamos o seguinte comando:

```
$ ssh -i "nome-do-arquivo.pem" admin@ec2-12-345-678-90.compute-1.amazonaws.com
```

Onde "nome-do-arquivo.pem" é o arquivo que criamos mais cedo nos pares de chaves, e o endereço depois de "admin@" é o da sua instancia.

Depois de conectado vamos instalar algumas coisas:

- Nginx
- PostgreSQL, MySQL ou MariaDB
- Rbenv
- Yarn

#### NGINX

Para instalar o nginx basta rodar o comando:

```sh
sudo apt update
sudo apt install nginx
```

Depois de instalado vamos configuralo. Crie o arquivo `reverse-proxy.conf` em `/etc/nginx/conf.d` e cole o seguinte conteúdo (substitua "nome_aplicacao" pelo nome da sua aplicação):

```
upstream app {
  server localhost:3000 fail_timeout=0;
}
server {
  listen 80;
  server_name nome_aplicacao;
  # ~2 seconds is often enough for most folks to parse HTML/CSS and
  # retrieve needed images/icons/frames, connections are cheap in
  # nginx so increasing this is generally safe...
  keepalive_timeout 5;
  # path for static files
  root /var/www/nome_aplicacao/nome_aplicacao/public;
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

Depois vamos criar o diretorio para os logs do nginx:

```
$ sudo mkdir -p /opt/app/log
```

E vamos remover os seguintes arquivos:

```
$ sudo rm /etc/nginx/sites-available/default
$ sudo rm /etc/nginx/sites-enabled/default
```

Então podemos checar se esta tudo ok com a configuração que fizemos no nginx atraves do comando:

```
$ sudo nginx -t

nginx: the configuration file /etc/nginx/nginx.conf syntax is ok
nginx: configuration file /etc/nginx/nginx.conf test is successful
```

Se obtivermos essa mensagem que tudo esta ok, podemos iniciar o nginx com o comando:
```
$ sudo service nginx start
```

Agora se tentarmos acessar nossa aplicação vamos obter um *502 Bad Gateway*.

#### POSTGRESQL, MYSQL OU MARIADB

##### MARIADB

```
$ sudo apt update
$ sudo apt install mariadb-server
$ sudo mysql_secure_installation
```

#### RBENV

```
$ sudo apt update
$ sudo apt install git curl libssl-dev libreadline-dev zlib1g-dev \
        autoconf bison build-essential libyaml-dev \
        libreadline-dev libncurses5-dev libffi-dev libgdbm-dev
$ git clone https://github.com/rbenv/rbenv.git ~/.rbenv
$ echo 'export PATH="$HOME/.rbenv/bin:$PATH"' >> ~/.bashrc
$ echo 'eval "$(rbenv init -)"' >> ~/.bashrc
$ source ~/.bashrc
$ git clone https://github.com/rbenv/ruby-build.git ~/.rbenv/plugins/ruby-build
$ rbenv install -l
$ rbenv install 3.1.0
$ rbenv global 3.1.0
$ echo "gem: --no-document" > ~/.gemrc
$ gem install bundler
```

#### YARN

```
$ curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | sudo apt-key add -
$ echo "deb https://dl.yarnpkg.com/debian/ stable main" | sudo tee /etc/apt/sources.list.d/yarn.list
$ sudo apt update
$ sudo apt install yarn
$ sudo apt install --no-install-recommends yarn
```

### 4. Configurando o repositorio da nossa aplicação

Agora vamos clonar o repositorio da nossa aplicação. Vamos fazer isso no seguinte diretorio `/var/www`. Antes de prosseguir, precisamos dar a permissão de acesso ao diretorio ao nosso usuario:
```
$ sudo chown -R admin /var/www
```

E então podemos clonar nosso repositorio em `/var/www`

```
$ git clone git@github.com:seu-usuario/seu-repositorio.git
```

Então acessamos nossa aplicação e executamos:

```
$ bundle install
```

Obs.: Provavelmente tera erros relacionados a instalação da gem da sua db, então dependendo de qual for, precisara instalar algumas coisas a mais:
- MariaDB: `$ sudo apt install libmariadb-dev-compat libmariadb-dev`

Após o `bundle install` ter dado certo, podemos testar nossa aplicação:

```
$ bundle exec rails db:create
$ bundle exec rails db:migrate
$ bundle exec rails s -b 0.0.0.0 -p 3000
```

Com isso agora podermos acessar nossa aplicação e ver ela funcionando.

### 5. Criando um serviço para iniciar a aplicação
Agora tudo que falta é criarmos um serviço para podermos iniciar nossa aplicação junto com a instancia. Para isso crie um arquivo chamado `run-server` na raiz do diretorio do usuario e cole o seguinte conteudo:

```
#!/bin/bash

cd /var/www/nome-aplicacao/nome-aplicacao
RAILS_ENV=production ~/.rbenv/shims/bundle install

# Precompile assets
RAILS_ENV=production ~/.rbenv/shims/bundle exec rake assets:precompile

# Remove a potentially pre-existing server.pid for Rails.
rm -f tmp/pids/server.pid

# Run the Rails server
RAILS_ENV=production ~/.rbenv/shims/bundle exec rails server -b 0.0.0.0 -p 3000
```

E alteramos suas permissões para podermos executalo:

```
$ chmod +x run-server
```

Então criamos um link simbolico em `/usr/local/bin/` com:

```
$ sudo ln -s ~/run-server /usr/local/bin
```

Antes, precisamos voltar ao diretorio da nossa aplicação pra gerar os secrets executando:
```
$ RAILS_ENV=production rake secret
```

Guarde o valor gerado para colocarmos abaixo.

Depois crie o arquivo `nome-aplicacao.service` em `/etc/systemd/system` e cole o seguinte conteudo:

```
[Unit]
Description=My Shell Script For Run My Server

[Service]
User=admin
Group=admin
Environment="SECRET_KEY_BASE=seu-token-gerado-no-rake-secret"
Environment="DATABASE_USER=root"
Environment="DATABASE_PASSWORD=root"
ExecStart=/usr/local/bin/run-server
```

Depois recarregamos com:

```
$ sudo systemctl daemon-reload
```

Por fim precisamos criar nossa base de dados e realizar as migrações. Para isso acesse novamente o diretorio da aplicação e execute:
```
RAILS_ENV=production SECRET_KEY_BASE=<seu-token-gerado-no-rake-secret> DATABASE_USER=<seu-usuario-db> DATABASE_PASSWORD=<sua-senha-db> bundle exec rails db:create

RAILS_ENV=production SECRET_KEY_BASE=<seu-token-gerado-no-rake-secret> DATABASE_USER=<seu-usuario-db> DATABASE_PASSWORD=<sua-senha-db> bundle exec rails db:migrate
```

### **Erros que podem ocorrer:**

#### **Erro relativo a um problema com o cache store**

Em `nosso_financeiro/config/application.rb` precisamos incluir:

> nosso_financeiro/config/application.rb

```ruby
...
config.active_record.cache_versioning = false
...
```
