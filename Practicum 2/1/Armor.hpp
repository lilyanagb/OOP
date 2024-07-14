/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Lilyana Belcheva
* @idnumber 62599
* @task 1
* @compiler VC
*/

#pragma once
#include <vector>
#include <utility>
#include <string>
#include <iostream>
using namespace std;

enum class ArmorTypes {
	cloth,
	leather,
	mail
};

class Armor
{
private:
	ArmorTypes type;
	int defense;
	vector<pair<string, double>> effects;
	int slots;
public:
	Armor();

	Armor(ArmorTypes, int);

	void setSlots(int);
	void setType(ArmorTypes);
	void setDefense(int);
	ArmorTypes getType() const;
	int getDefense() const;
	int getSlots() const;

	double getGearscore();
	void addEffect(string, double);
	void removeEffect(string);
	bool changeEffect(string, double);

	void print();
};

