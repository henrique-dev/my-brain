## Inversão de controle
Para entender esses conceitos, saiba que a Inversão de Controle (IoC - Inversion of Control) permite delegar a outro elemento o controle sobre como e quando um objeto deve ser criado e quando um método deve ser executado, por exemplo. Assim, essas responsabilidades, isto é, o controle sobre a execução de alguns comportamentos, passa a ser gerenciado por esse elemento, não cabendo mais a nós, programadores, definirmos isso.

No caso do Spring, chamamos esse elemento de container. Temos, assim, o princípio da inversão do controle. Para melhor compreensão, vejamos um exemplo à parte: Ao construir a interface gráfica com Swing, não precisamos ficar verificando se o usuário clicou em um botão. Precisamos apenas implementar uma ação para aquele botão e pronto. Assim que ele for clicado, essa ação será executada sem que precisemos nos preocupar com isso.

## Processo de Desenvolvimento no Spring
### 1 - Configurar seu Spring Beans
Um "Spring Bean" é simplesmente um objeto Java.

Quando os objetos Java são criados pelo Spring Container, o Spring se refere a eles como "Spring Beans".

Spring Beans são criados a partir de classes Java normais... assim como objetos Java.
> applicationContext.xml
```xml
<beans ...>
    <bean id="myCoach"
        class="com.br.phdev.springdemo.BaseballCoach">
    </bean>
</beans>
```
### 2 - Criar um Spring Container
Um Spring Container é conhecido como ApplicationContext

Implementação especiais:
- ClassPathXmlApplicationContext
- AnnoationConfigApplicationContext
- GenericWebApplicationContext
- Outros

> ClassPathXmlApplicationContext.java
```java
ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
```

### 3 - Recuperar Beans do Spring Container
> ClassPathXmlApplicationContext.java
```java
Coach theCoach = context.getBean("myCoach", Coach.class);
```