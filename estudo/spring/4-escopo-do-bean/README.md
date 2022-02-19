## Escopo do Bean
- O escopo se refere ao ciclo de vida de um Bean
- O quanto um Bean pode existir?
- Quantas instancias podem haver?
- Como o Bean é compartilhado?

## Escopo Padrão
O escopo padrão de um Bean é Singleton
```xml
<beans ...>
    <bean id="myCoach"
        class="com.br.phdev.springdemo.TrackCoach">
    </bean>
</beans>
```
### Singleton
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

## Tipos de Escopo para o Bean
Escopo | Descrição
--- | ---
singleton | Cria uma unica instancia compartilhada do Bean. Escopo padrão.
prototype | Cria uma nova instancia do Bean para cada requisição feita ao container.
request | Deixa o escopo vísivel durante uma requisição web HTTP. Somente para uso de web apps.
session | Deixa o escopo vísivel durante uma sessão web HTTP. Somente para uso de web apps.
global-session | Deixa o escopo vísivel globalmente durante uma sessão web HTTP. Somente para uso de web apps.