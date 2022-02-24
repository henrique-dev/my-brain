## Como adicionar um usuário ao grupo sudo no debian
```
$ su -
# usermod -aG sudo <username>
# su <username>
```

## Como instalar os adicionais de convidados do VirtualBox
```
$ sudo apt update
$ sudo apt install build-essential dkms linux-headers-$(uname -r)
```
E então no menu da maquina virtual, Dispositivos -> "Inserir imagem de CD dos adicionais para convidado". Depois:
```
$ sudo mkdir -p /mnt/cdrom
$ sudo mount /dev/cdrom /mnt/cdrom
$ cd /mnt/cdrom
$ sudo sh ./VBoxLinuxAdditions.run --nox11
```
A saída será parecida como abaixo:
```
Verifying archive integrity... All good.
Uncompressing VirtualBox 6.0.16 Guest Additions for Linux........
...
...
VirtualBox Guest Additions: Starting.
```
Depois:
```
$ sudo shutdown -r now
```
## Como instalar o Yarn
```
$ curl -sS https://dl.yarnpkg.com/debian/pubkey.gpg | sudo apt-key add -
$ echo "deb https://dl.yarnpkg.com/debian/ stable main" | sudo tee /etc/apt/sources.list.d/yarn.list
$ sudo apt update
$ sudo apt install yarn
$ sudo apt install --no-install-recommends yarn
```

## Como instalar o apache tomcat
```
$ sudo apt update
$ sudo apt install default-jdk
$ sudo mkdir /opt/tomcat
$ sudo groupadd tomcat
$ sudo useradd -s /bin/false -g tomcat -d /opt/tomcat tomcat
$ curl -O https://dlcdn.apache.org/tomcat/tomcat-9/v9.0.58/bin/apache-tomcat-9.0.58.tar.gz
$ sudo tar xzvf apache-tomcat-9*tar.gz -C /opt/tomcat --strip-components=1
$ cd /opt/tomcat
$ sudo chgrp -R tomcat /opt/tomcat
$ sudo chmod -R g+r conf
$ sudo chmod g+x conf
$ sudo chown -R tomcat webapps/ work/ temp/ logs/
$ sudo update-java-alternatives -l
```
Depois de já termos nosso JAVA_HOME, podemos criar o serviço através do ```systemmd``` com o arquivo chamado ```tomcat.service``` no diretório ```/etc/systemd/system``` rodando o comando:
```
$ sudo nano /etc/systemd/system/tomcat.service
```
Cole o seguinte conteúdo dentro do arquivo ```tomcat.service```.
> /etc/systemd/system/tomcat.service
```
[Unit]
Description=Apache Tomcat Web Application Container
After=network.target

[Service]
Type=forking

Environment=JAVA_HOME=/usr/lib/jvm/java-1.11.0-openjdk-amd64
Environment=CATALINA_PID=/opt/tomcat/temp/tomcat.pid
Environment=CATALINA_HOME=/opt/tomcat
Environment=CATALINA_BASE=/opt/tomcat
Environment='CATALINA_OPTS=-Xms512M -Xmx1024M -server -XX:+UseParallelGC'
Environment='JAVA_OPTS=-Djava.awt.headless=true -Djava.security.egd=file:/dev/./urandom'

ExecStart=/opt/tomcat/bin/startup.sh
ExecStop=/opt/tomcat/bin/shutdown.sh

User=tomcat
Group=tomcat
UMask=0007
RestartSec=10
Restart=always

[Install]
WantedBy=multi-user.target
```
Em seguida termos que recarregar o ```systemmd``` para aplicar as novas mudanças, para ele reconhecer o arquivo ```tomcat.service```.
```
$ sudo systemctl daemon-reload
$ sudo systemctl start tomcat
$ systemctl status tomcat
$ systemctl enable tomcat
```

## Como instalar o Postman
```
$ wget https://dl.pstmn.io/download/latest/linux64 -O postman-linux-x64.tar.gz
$ sudo tar -xzf postman-linux-x64.tar.gz -C /opt
$ sudo ln -s /opt/Postman/Postman /usr/bin/postman
$ nano ~/.local/share/applications/Postman.desktop
```
Em seguida cole o seguinte conteúdo:
```
[Desktop Entry]
Encoding=UTF-8
Name=Postman
Exec=/opt/Postman/app/Postman %U
Icon=/opt/Postman/app/resources/app/assets/icon.png
Terminal=false
Type=Application
Categories=Development;
```