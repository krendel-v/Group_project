#include "Game.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	CityList C("a.txt");

	Game game;
	game.start(&C);

	system("pause");
	return 0;
}
