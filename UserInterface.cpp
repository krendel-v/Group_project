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
	cout << "���������� � ���� �������: " << endl;
	cout << "1. ������ ��������� ������� ����� ���� ����� �����." << endl;
	cout << "2. ������ ��������� ���������� � ��������� ����� �����������" << endl;
	cout << "   ������(���� �������� ������������� �� �, �, � - �� ������ ������������� �����)." << endl;
	cout << "3. � ������� �� ������ ���� ���� ���������� �������." << endl;
	cout << "4. ���� ������� ������������ � ��������� �����." << endl;
	cout << "5. ��� ��������� ���� �������� �����." << endl;
}
void UserInterface::printCommands() {
	cout << "--------------------------------------------" << endl;
	cout << "��������� ���������� ������� �� ����� ����:" << endl;
	cout << "1. /���� - ��� ��������� ����" << endl;
	cout << "2. /������ - ��� ������ ������ ��������� �������" << endl;
	cout << "--------------------------------------------" << endl;
}
int UserInterface::printMenu() {
	string m, m1;
	int n, n1;
	cout << "���� ��������" << endl;
	cout << "����: " << endl;
	cout << "0) ����������" << endl;
	cout << "1) ������ ������ ����������" << endl;
	cout << "2) ������ ������" << endl;
	cout << "3) ��������� ������ ����������" << endl;
	cout << "4) ����� �� ����" << endl;
	while (true) {
		cin >> m;
		if (thisInt(m)) {
			n = stoi(m); break;
		}
		else cout << "������� �����!" << endl;
	}
	switch (n) {
	case 0: printRules(); cout << endl; return -1;
	case 1: {
		cout << "��� ����� ������ ������?" << endl;
		cout << "1) ���������" << endl;
		cout << "2) �" << endl;
		while (true) {
			cin >> m1;
			if (thisInt(m1)) {
				n1 = stoi(m1); break;
			}
			else cout << "������� �����!" << endl;
		}
		if (n1 == 1) return 1;
		else return 2;
	}
	case 2: return 3;
	case 3: return 4;
	case 4: cout << "�� ����� �� ���������." << endl; return 0;
	default: return 5;
	}
}
void UserInterface::printHod(int k) {
	cout << "��� " << k << ":" << endl;
}
void UserInterface::printGame(CityList* G) {
	cout << "--------------------------------------------" << endl;
	cout << "������ ��������� �������: " << endl;
	if (G->citiesCount()) G->print();
	else cout << "�� ������ ���� ������ ����!" << endl;
	cout << "--------------------------------------------" << endl;
}
void UserInterface::inputName(Player* P) {
	P->writeName();
}
void UserInterface::printWin(Player* P) {
	cout << "����������: " << P->printName() << endl << endl;
}
UserInterface::~UserInterface() {}
