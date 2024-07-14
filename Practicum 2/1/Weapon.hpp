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
#include <string>
#include <utility>
#include <vector>
using namespace std;

enum class HandleTypes {
	oneHanded,
	twoHanded
};

class Weapon
{
private:
	HandleTypes type;
	string weaponKind;
	int slots;

	pair<double, double> hitDamage;
	vector<pair<string, double>> effects;

public:
	Weapon();
	Weapon(HandleTypes, string, double, double);

	HandleTypes getType() const;
	string getWeaponKind() const;
	int getSlots() const;

	void changeWeaponKind(string);

	void changeHandleTypes(HandleTypes);

	void addEffect(string, double);
	void removeEffect(string);
	bool changePowerEffect(string, double);

	double getWeaponScore();
	int checkType(string);
	void print();
};