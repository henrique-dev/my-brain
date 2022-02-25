package com.br.phdev.springdemo;

public class TrackCoach extends Coach {

	public TrackCoach(FortuneService theFortuneService) {
		super(theFortuneService);
		// TODO Auto-generated constructor stub
	}

	@Override
	public String getDailyWorkout() { 
		return "Run a hard 5k";
	}

	@Override
	public String getDailyFortune() {
		// TODO Auto-generated method stub
		return null;
	}

}
