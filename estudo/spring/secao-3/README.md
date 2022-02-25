## Injeção de dependência
E a Injeção de Dependência? A Injeção de Dependência (DI - Dependency Injection) é uma das maneiras de implementar a Inversão de Controle. Com a Injeção de Dependência a classe deixa de se preocupar em como resolver as suas dependências. Ela passa a manter o foco apenas no uso dos recursos das dependências para realizar as tarefas que precisa. E isso leva a uma das características mais conhecidas quando programamos com Spring: não precisamos utilizar o ```new``` para criar os objetos por ele gerenciados, pois isso passa a ser feito pelo framework.

Existem muitos tipos de injeção com o Spring
Aqui serão mostradas as duas mais comuns:
- Contrutor Injection
- Setter Injection
- Literal Values Injection
- Property File Injection
Será mostrado sobre "auto-wiring" nas anotações nas proximas seções

## Contrutor Injection - Processo de Desenvolvimento
### 1 - Definir a dependência de interace e classe
> FortuneService.java
```java
public interface FortuneService {
    public String getFortune();
}
```
> HappyFortuneService.java
```java
public class HappyFortuneService implements FortuneService {
    public String getFortune() {
        return "Today is your lucky day!";
    }
}
```
### 2 - Criar um contrutor na sua classe para as injeções
> BaseballCoach.java
```java
public class BaseballCoach implements Coach {
    
    private FortuneService fortuneService;

    public BaseballCoach(FortuneService theFortuneService) {
        fortuneService = theFortuneService;
    }

}
```

### 3 - Configurar a injeção de dependência no arquivo de configuração do spring
> applicationContext.xml
```xml
<bean id="myFortuneService"
    class="com.br.phdev.springdemo.HappyFortuneService">
</bean>
<bean id="myCoach"
    class="com.br.phdev.springdemo.BaseballCoach">
    <contructor-arg ref="myFortuneService">
</bean>
```

## Setter Injection - Processo de Desenvolvimento
### 1 - Criar metodos setters na sua classe para as injeções
> CricketCoach.java
```java
public class CricketCoach implements Coach {

    private FortuneService fortuneService;

    public CricketCoach() {
    }

    public void setFortuneService(FortuneService fortuneService) {
        this.fortuneService = fortuneService;
    }

}
```
### 2 - Configurar a injeção de dependência no arquivo de configuração do spring
> applicationContext.xml
```xml
<bean id="myFortuneService"
    class="com.br.phdev.springdemo.HappyFortuneService">
</bean>
<bean id="myCricketCoach"
    class="com.br.phdev.springdemo.CricketCoach">
    <property name="fortuneService" ref="myFortuneService" />
</bean>
```

## Literal Values Injection - Processo de Desenvolvimento
### 1 - Criar metodos setters na sua classe para as injeções
> CricketCoach.java
```java
public class CricketCoach implements Coach {

    private String emailAddress;
    private String team;

    public void setEmailAddress(String emailAddress) ...

    public void setTeam(String team) ...

}
```
### 2 - Configurar a injeção de dependência no arquivo de configuração do spring
> applicationContext.xml
```xml
<bean id="myCricketCoach"
    class="com.br.phdev.springdemo.CricketCoach">    

    <property name="emailAddress" value="henrique.phgb@gmail.com" />

    <property name="team" value="HeadRed" />
</bean>
```

## Property File Injection - Processo de Desenvolvimento
### Criar o arquivo de configuração
> sport.properties
```js
foo.email=henrique.phgb@gmail.com
foo.team=HeadRed
```
### Carregar o arquivo de configuração no Spring
> applicationContext.xml
```xml
<context:property-placeholder location="classpath:sport.properties" />
```
### Referenciar os valores do arquivo de configuração
> applicationContext.xml
```xml
<bean id="myCricketCoach"
    class="com.br.phdev.springdemo.CricketCoach">    

    <property name="emailAddress" value="${foo.email}" />

    <property name="team" value="${foo.team}" />
</bean>
```