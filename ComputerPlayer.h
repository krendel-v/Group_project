#pragma once
#include "CityList.h"
#include "Player.h"
#include <ctime>
#include<vector>

// ����� ������������� �����
class ComputerPlayer :public Player
{
public:
	ComputerPlayer();
	string choiceOne(CityList* C); //choice1
	string choice(CityList* C, CityList* G);
	~ComputerPlayer();
};

