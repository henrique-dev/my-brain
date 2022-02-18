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