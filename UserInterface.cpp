#include "UserInterface.h"
#include "ctype.h"

bool thisInt(string str) {
	setlocale(LC_ALL, "russian");
	if (str.length() == 0) return 0;
	for (int i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])) {
			return 0;
		}
	}
	return 1;
}
UserInterface::UserInterface() {}
void UserInterface::printRules() {
	cout << "Инструкция к игре «Города»: " << endl;
	cout << "1. Первым элементом цепочки может быть любой город." << endl;
	cout << "2. Каждый следующий начинается с последней буквы предыдущего" << endl;
	cout << "   города(если название заканчивается на ь, ъ, ы - то берётся предпоследняя буква)." << endl;
	cout << "3. В цепочке не должно быть двух одинаковых городов." << endl;
	cout << "4. Ввод городов производится с маленькой буквы." << endl;
	cout << "5. Для окончания игры напишите «Стоп»." << endl;
}
void UserInterface::printCommands() {
	cout << "--------------------------------------------" << endl;
	cout << "Доступные консольные команды во время игры:" << endl;
	cout << "1. /Стоп - для окончания игры" << endl;
	cout << "2. /Города - для вывода списка названных городов" << endl;
	cout << "--------------------------------------------" << endl;
}
int UserInterface::printMenu() {
	string m, m1;
	int n, n1;
	cout << "ИГРА «ГОРОДА»" << endl;
	cout << "Меню: " << endl;
	cout << "0) Инструкция" << endl;
	cout << "1) Играть против компьютера" << endl;
	cout << "2) Играть вдвоем" << endl;
	cout << "3) Компьютер против компьютера" << endl;
	cout << "4) Выход из игры" << endl;
	while (true) {
		cin >> m;
		if (thisInt(m)) {
			n = stoi(m); break;
		}
		else cout << "Введите число!" << endl;
	}
	switch (n) {
	case 0: printRules(); cout << endl; return -1;
	case 1: {
		cout << "Кто будет ходить первым?" << endl;
		cout << "1) Компьютер" << endl;
		cout << "2) Я" << endl;
		while (true) {
			cin >> m1;
			if (thisInt(m1)) {
				n1 = stoi(m1); break;
			}
			else cout << "Введите число!" << endl;
		}
		if (n1 == 1) return 1;
		else return 2;
	}
	case 2: return 3;
	case 3: return 4;
	case 4: cout << "Вы вышли из программы." << endl; return 0;
	default: return 5;
	}
}
void UserInterface::printHod(int k) {
	cout << "Ход " << k << ":" << endl;
}
void UserInterface::printGame(CityList* G) {
	cout << "--------------------------------------------" << endl;
	cout << "Список названных городов: " << endl;
	if (G->citiesCount()) G->print();
	else cout << "На первом ходу список пуст!" << endl;
	cout << "--------------------------------------------" << endl;
}
void UserInterface::inputName(Player* P) {
	P->writeName();
}
void UserInterface::printWin(Player* P) {
	cout << "Победитель: " << P->printName() << endl << endl;
}
UserInterface::~UserInterface() {}
