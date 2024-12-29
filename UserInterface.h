#pragma once
#include "CityList.h"
#include "ComputerPlayer.h"

// класс «Интерфейс пользователя»
class UserInterface
{
public:
	UserInterface();
	static void printRules();
	static void printCommands();
	static int printMenu();
	static void printHod(int k);
	static void printGame(CityList* G);
	static void inputName(Player* P);
	static void printWin(Player* P);
	~UserInterface();
};


