#include "Player.h"

Player::Player(): name() {}
Player::Player(string name) :name(name) {}
string Player::printName() { return name; }
void Player::writeName() {
	string name;
	cout << "������� ��� ������: ";
	getline(cin, name);
	this->name = name;
}
Player::~Player() {}
