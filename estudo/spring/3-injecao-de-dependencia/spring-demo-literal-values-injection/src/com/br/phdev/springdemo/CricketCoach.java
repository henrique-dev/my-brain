package com.br.phdev.springdemo;

public class CricketCoach extends Coach {
	
	private String emailAddress;
	private String team;
	
	
	public CricketCoach() {
		System.out.println("CricketCoach: inside no-arg constructor");
	}
	
	public CricketCoach(FortuneService fortuneService) {
		super(fortuneService);
	}
	
	@Override
	public String getDailyWorkout() {
		return "Practice fast bowling for 15 minutes";
	}

	@Override
	public String getDailyFortune() {
		return fortuneService.getFortune();
	}
	
	@Override
	public void setFortuneService(FortuneService fortuneService) {
		System.out.println("CricketCoach: inside setter method - setFortuneService");
		this.fortuneService = fortuneService;
	}

	public String getEmailAddress() {
		return emailAddress;
	}

	public void setEmailAddress(String emailAddress) {
		this.emailAddress = emailAddress;
	}

	public String getTeam() {
		return team;
	}

	public void setTeam(String team) {
		this.team = team;
	}
	
	

}
