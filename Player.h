#pragma once
#include <iostream>
#include <string>

using namespace std;
// ����� ������
class Player
{
	string name;
public:
	Player();
	Player(string name);
	string printName(); //gettName
	void writeName(); //setName
	~Player();
};


