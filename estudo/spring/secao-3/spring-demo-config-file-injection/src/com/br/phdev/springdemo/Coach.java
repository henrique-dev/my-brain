package com.br.phdev.springdemo;

public abstract class Coach implements CoachService {
	
	// define um campo privado para a dependencia
	protected FortuneService fortuneService;
	
	public Coach() {
		
	}
	
	public Coach(FortuneService theFortuneService) {
		fortuneService = theFortuneService;
	}

	public FortuneService getFortuneService() {
		return fortuneService;
	}

	public void setFortuneService(FortuneService fortuneService) {
		this.fortuneService = fortuneService;
	}	
	
	

}
