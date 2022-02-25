package com.br.phdev.springdemo;

public abstract class Coach implements CoachService {
	
	// define um campo privado para a dependencia
	protected FortuneService fortuneService;
	
	public Coach(FortuneService theFortuneService) {
		fortuneService = theFortuneService;
	}	

}
