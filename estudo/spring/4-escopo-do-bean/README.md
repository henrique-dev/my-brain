## Escopo do Bean
- O escopo se refere ao ciclo de vida de um Bean
- O quanto um Bean pode existir?
- Quantas instancias podem haver?
- Como o Bean é compartilhado?

## Tipos de Escopo para o Bean
Escopo | Descrição
--- | ---
singleton | Cria uma unica instancia compartilhada do Bean. Escopo padrão.
prototype | Cria uma nova instancia do Bean para cada requisição feita ao container.
request | Deixa o escopo vísivel durante uma requisição web HTTP. Somente para uso de web apps.
session | Deixa o escopo vísivel durante uma sessão web HTTP. Somente para uso de web apps.
global-session | Deixa o escopo vísivel globalmente durante uma sessão web HTTP. Somente para uso de web apps.

O escopo padrão de um Bean é Singleton
```xml
<beans ...>
    <bean id="myCoach"
        class="com.br.phdev.springdemo.TrackCoach">
    </bean>
</beans>
```
E a o propriedade que usamos para definir o escopo é ```scope="singleton">```.
### Escopo singleton
O Singleton é um padrão de projeto criacional que permite a você garantir que uma classe tenha apenas uma instância, enquanto provê um ponto de acesso global para essa instância.

Com isso o Spring Container cria apenas uma instancia do Bean por padrão. Ele fica em cache na memoria, e todas as requisições desse Bean compartilharão a mesma referencia.

Logo no seguinte exemplo as instancias compartilhariam o mesmo Bean:
```java
Coach theCoach = context.getBean("myCoach", Coach.class);
Coach alphaCoach = context.getBean("myCoach", Coach.class);
```

Pode se deixar explicito o uso do escopo Singleton para o Bean:
```xml
<beans ...>
    <bean id="myCoach"
        class="com.br.phdev.springdemo.TrackCoach"
        scope="singleton">
    </bean>
</beans>
```

### Escopo prototype
Nesse escopo sempre que é o Bean é requisitado, é criado um novo objeto.
```xml
<beans ...>
    <bean id="myCoach"
        class="com.br.phdev.springdemo.TrackCoach"
        scope="prototype">
    </bean>
</beans>
```
Logo no seguinte exemplo as instancias não compartilhariam o mesmo Bean:
```java
Coach theCoach = context.getBean("myCoach", Coach.class);
Coach alphaCoach = context.getBean("myCoach", Coach.class);
```

## Ciclo de vida do Bean
Quando um Container Spring é criado, algumas coisas acontecem:
1. Primeiro o Bean é instanciado
2. Depois as depedencias são injetadas
3. Depois acontece algum processamento interno no Spring
4. E então você tem a opção de criar seu próprio metodo de inicialização
    - Nesse ponto o Bean já esta pronto pra uso.

### Metodos/Hooks do ciclo de vida do Bean
Se pode adicionar declarações de codigo durante a inicizalização do Bean, seja a logica de negocio ou definindo _handles_ de recursos (_db_, _sockets_, arquivos, etc).
Também é possivel faz o mesmo durante a destruição de um Bean, podendo dessa vez limpar os recursos adquiridos durante a inicialização (_db_, _sockets_, arquivos, etc).

### Adicionando Metodos/Hooks no Bean
Podemos adicionar os metodos na inicialização atraves da propriedade ```init-method="doMyStartupStuff"```.
```xml
<beans ...>
    <bean id="myCoach"
        class="com.br.phdev.springdemo.TrackCoach"
        init-method="doMyStartupStuff">
    </bean>
</beans>
```
E os metodos na destruição atraves da propriedade ```destroy-method="doMyCleanupStuff"```.
```xml
<beans ...>
    <bean id="myCoach"
        class="com.br.phdev.springdemo.TrackCoach"
        init-method="doMyStartupStuff"
        destroy-method="doMyCleanupStuff">
    </bean>
</beans>
```

### Processo de desenvolvimento
#### 1 - Definir os metodos de inicialização e destruição
#### 2 - Configurar os nomes dos metodos no arquivo de configuração do Spring