#include "CityList.h"

CityList::CityList() :cities() {}
CityList::CityList(string file) {
	string str;
	ifstream in(file);
	if (in)
	{
		while (!in.eof())
		{
			in >> str;
			cities.push_back(str);
		}
		in.close();
	}
	else cout << "Такого файла нет!" << endl;
}
list<string>::iterator CityList::beginCities() { return cities.begin(); }
list<string>::iterator CityList::endCities() { return cities.end(); }
size_t CityList::citiesCount() { return cities.size(); }
void CityList::addCity(CityList* C, string c) {
	if (isCityFirst(c) && cityExists(C, c))cities.push_back(c);
}
bool CityList::isCityFirst(string c) {
	return (count(cities.begin(), cities.end(), c) == 0);
}
bool CityList::cityExists(CityList* C, string c) {
	if (find(C->cities.begin(), C->cities.end(), c) != C->cities.end()) return 1;
	else return 0;
}
string CityList::retrieveLastCity() {
	return *(--cities.end());
}
void CityList::print() {
	copy(cities.begin(), cities.end(), ostream_iterator<string>(cout, "\n"));
}
void CityList::clearCities() {
	cities.clear();
}
CityList::~CityList() {
	clearCities();
}