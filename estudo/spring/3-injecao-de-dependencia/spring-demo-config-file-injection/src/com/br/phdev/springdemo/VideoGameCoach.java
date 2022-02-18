package com.br.phdev.springdemo;

public class VideoGameCoach extends Coach {	

	public VideoGameCoach(FortuneService theFortuneService) {
		super(theFortuneService);
	}

	@Override
	public String getDailyWorkout() {
		return "Win the game ever";
	}

	@Override
	public String getDailyFortune() {
		return "Today can be your lucky day!";
	}

}
