package com.br.phdev.springdemo;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class HelloSpringApp {

	public static void main(String[] args) {
	
		// carrega o arquivo de configuração do spring
		ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
		
		// recupera o bean do spring container
		Coach theCoach = context.getBean("myCoach", Coach.class);
		
		// chama os metodo do bean
		System.out.println(theCoach.getDailyWorkout());
		
		// finaliza o contexto
		context.close();

	}

}
