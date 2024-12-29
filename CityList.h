#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <windows.h>

using namespace std;
// класс «Города»
class CityList
{
	list<string> cities;
public:

	CityList();
	CityList(string file);
	list<string>::iterator beginCities(); //get_cities_begin
	list<string>::iterator endCities(); //get_cities_end
	size_t citiesCount(); //get_cities_size
	void addCity(CityList* C, string c); //appCity
	bool isCityFirst(string c); //is_first
	bool cityExists(CityList* C, string c); //is_realy
	string retrieveLastCity(); //endCity
	void print();
	void clearCities(); //cities_clear
	~CityList();
};
