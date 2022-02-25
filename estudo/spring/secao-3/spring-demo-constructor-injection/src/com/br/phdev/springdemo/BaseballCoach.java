package com.br.phdev.springdemo;

public class BaseballCoach extends Coach {

	public BaseballCoach(FortuneService theFortuneService) {
		super(theFortuneService);
	}

	@Override
	public String getDailyWorkout() {
		return "Spend 30 minutes on batting practice";
	}

	@Override
	public String getDailyFortune() {
		return fortuneService.getFortune();
	}
	
}
