#include "ComputerPlayer.h"

ComputerPlayer::ComputerPlayer() :Player("���������") { }
string ComputerPlayer::choiceOne(CityList* C) {
	srand(time(0));
	list<string>::iterator s = C->beginCities();
	advance(s, rand() % C->citiesCount());
	return *s;
}
string ComputerPlayer::choice(CityList* C, CityList* G) {
	string str("/����");
	int l = G->retrieveLastCity().length();
	char s = G->retrieveLastCity()[l - 1];
	if (s == '�' || s == '�' || s == '�') s = G->retrieveLastCity()[l - 2];
	vector<string>::iterator iter;
	vector<string> V(C->beginCities(), C->endCities());
	random_shuffle(V.begin(), V.end());

	for (iter = V.begin(); iter != V.end(); ) {
		if ((*iter)[0] == s) {
			if (G->isCityFirst(*iter)) return *iter;
			if (!G->isCityFirst(*iter)) iter++;
		}
		else iter++;
		if (iter == V.end()) return str;
	}
}
ComputerPlayer::~ComputerPlayer() {}