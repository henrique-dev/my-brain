## Como instalar o rbenv
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
