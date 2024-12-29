#include "Game.h"

Game::Game() : CP(), CP2(), P1(), P2(), G(), hod(1), GOver(0) {}

void Game::start(CityList* C) {
	int main_choice = UserInterface::printMenu();
	while (main_choice != 0) {
		if (main_choice == 1) {
			CP_vs_P1(C);
			clearing();
		}
		else if (main_choice == 2) {
			P1_vs_CP(C);
			clearing();
		}
		else if (main_choice == 3) {
			P1_vs_P2(C);
			clearing();
		}
		else if (main_choice == 4) {
			CP_vs_CP2(C);
			clearing();
		}
		main_choice = UserInterface::printMenu();
	}
}

void Game::CP_vs_P1(CityList* C) {
	bool first_hod = true;
	string city;
	int ms = 1500;
	UserInterface::printCommands();
	cin.ignore();
	UserInterface::inputName(&P1);

	while (!GameOver()) {
		UserInterface::printHod(hod);
		cout << CP.printName() << ": ";
		hod++;
		if (first_hod) {
			city = CP.choiceOne(C);
			G.addCity(C, city);
			first_hod = false;
			Sleep(ms);
			cout << city << endl;
		}
		else {
			city = CP.choice(C, &G);
			if (city == "/Стоп") {
				GOver = true;
				Sleep(ms); 
				cout << city << endl;
				UserInterface::printWin(&P1);
			}
			else {
				G.addCity(C, city);
				Sleep(ms);
				cout << city << endl;
			}
		}

		if (!GameOver()) {
			UserInterface::printHod(hod);
			hod++;
			do
			{
				cout << P1.printName() << " введите город на букву " << getNextCharacter() << ": ";
				getline(cin, city);
				if (city == "/Стоп") {
					GOver = true;
					UserInterface::printWin(&CP);
				}
				if (city == "/Города") UserInterface::printGame(&G);

			} while (!validateCity(C, city) && city != "/Стоп");
			G.addCity(C, city);
		}
	}
}

void Game::P1_vs_CP(CityList* C) {
	bool first_hod = true;
	string city;
	int ms = 1500;
	UserInterface::printCommands();
	cin.ignore();
	UserInterface::inputName(&P1);

	while (!GameOver()) {
		UserInterface::printHod(hod);
		hod++;

		if (first_hod) {
			do
			{
				cout << P1.printName() << " введите город: ";
				getline(cin, city);
				if (city == "/Стоп") {
					GOver = true;
					UserInterface::printWin(&CP);
				}
				if (city == "/Города") UserInterface::printGame(&G);
			} while (!validateFirstCity(C, city) && city != "/Стоп");
			G.addCity(C, city);

			first_hod = false;
		}
		else {
			do
			{
				cout << P1.printName() << " введите город на букву " << getNextCharacter() << ": ";
				getline(cin, city);
				if (city == "/Стоп") {
					GOver = true;
					UserInterface::printWin(&CP);
				}
				if (city == "/Города") UserInterface::printGame(&G);
			} while (!validateCity(C, city) && city != "/Стоп");
			G.addCity(C, city);
		}

		if (!GameOver()) {
			UserInterface::printHod(hod);
			hod++;
			cout << CP.printName() << ": ";
			city = CP.choice(C, &G);
			if (city == "/Стоп") {
				GOver = true;
				Sleep(ms);
				cout << city << endl;
				UserInterface::printWin(&P1);
			}
			else {
				G.addCity(C, city);
				Sleep(ms);
				cout << city << endl;
			}
		}
	}
}

void Game::P1_vs_P2(CityList* C) {
	bool first_hod = true;
	string city;
	UserInterface::printCommands();
	cin.ignore();
	UserInterface::inputName(&P1);
	UserInterface::inputName(&P2);

	while (!GameOver()) {
		UserInterface::printHod(hod);
		hod++;

		if (first_hod) {
			do
			{
				cout << P1.printName() << " введите город: ";
				getline(cin, city);
				if (city == "/Стоп") {
					GOver = true;
					UserInterface::printWin(&P2);
				}
				if (city == "/Города") UserInterface::printGame(&G);
			} while (!validateFirstCity(C, city) && city != "/Стоп");
			G.addCity(C, city);

			first_hod = false;
		}
		else {
			do
			{
				cout << P1.printName() << " введите город на букву " << getNextCharacter() << ": ";
				getline(cin, city);
				if (city == "/Стоп") {
					GOver = true;
					UserInterface::printWin(&P2);
				}
				if (city == "/Города") UserInterface::printGame(&G);
			} while (!validateCity(C, city) && city != "/Стоп");
			G.addCity(C, city);
		}

		if (!GameOver()) {
			UserInterface::printHod(hod);
			hod++;
			do
			{
				cout << P2.printName() << " введите город на букву " << getNextCharacter() << ": ";
				getline(cin, city);
				if (city == "/Стоп") {
					GOver = true;
					UserInterface::printWin(&P1);
				}
				if (city == "/Города") UserInterface::printGame(&G);
			} while (!validateCity(C, city) && city != "/Стоп");
			G.addCity(C, city);
		}
	}
}

void Game::CP_vs_CP2(CityList* C) {
	bool first_hod = true;
	string city;
	int ms = 2000;
	cin.ignore();
	UserInterface::inputName(&CP);
	UserInterface::inputName(&CP2);

	while (!GameOver()) {
		UserInterface::printHod(hod);
		cout << CP.printName() << ": ";
		hod++;
		if (first_hod) {
			city = CP.choiceOne(C);
			G.addCity(C, city);
			first_hod = false;
			Sleep(ms);
			cout << city << endl;
		}
		else {
			city = CP.choice(C, &G);
			if (city == "/Стоп") {
				GOver = true;
				Sleep(ms); 
				cout << city << endl;
				UserInterface::printWin(&CP2);
			}
			else {
				G.addCity(C, city);
				Sleep(ms); 
				cout << city << endl;
			}
		}

		if (!GameOver()) {
			UserInterface::printHod(hod);
			hod++;
			cout << CP2.printName() << ": ";
			city = CP2.choice(C, &G);
			if (city == "/Стоп") {
				GOver = true;
				Sleep(ms);
				cout << city << endl;
				UserInterface::printWin(&CP);
			}
			else {
				G.addCity(C, city);
				Sleep(ms); 
				cout << city << endl;
			}
		}
	}
}

bool Game::GameOver() const { return GOver; }

char Game::getNextCharacter() {
	int l = G.retrieveLastCity().length();
	char s = G.retrieveLastCity()[l - 1];
	if (s == 'ы' || s == 'ъ' || s == 'ь') {
		s = G.retrieveLastCity()[l - 2];
		return s;
	}
	return s;
}

bool Game::validateCity(CityList* C, string city) {
	return (G.isCityFirst(city) && G.cityExists(C, city) && city[0] == getNextCharacter());
}

bool Game::validateFirstCity(CityList* C, string city) {
	return G.cityExists(C, city);
}

void Game::clearing() {
	GOver = 0;
	hod = 1;
	G.clearCities();
}

Game::~Game() {
	clearing();
}
