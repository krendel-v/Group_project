#pragma once
#include "UserInterface.h"

// класс «Игра»
class Game
{
	ComputerPlayer CP;
	ComputerPlayer CP2;
	Player P1;
	Player P2;
	CityList G;
	int hod;
	bool GOver;
public:

	Game();
	void start(CityList* C); //start_game
	void CP_vs_P1(CityList* C);
	void P1_vs_CP(CityList* C);
	void P1_vs_P2(CityList* C);
	void CP_vs_CP2(CityList* C);
	bool GameOver() const;
	char getNextCharacter(); //next_letter
	bool validateCity(CityList* C, string city); //check_city
	bool validateFirstCity(CityList* C, string city); //check_city_first
	void clearing(); //game_clearing
	~Game();

};


