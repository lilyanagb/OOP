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

#include <iostream>
#include <vector>
#include "Weapon.hpp"
using namespace std;

double Weapon::getWeaponScore()
{
	double weaponScore = (hitDamage.first + hitDamage.second) / 2;
	int size = effects.size();
	for (int i = 0; i < size; i++) {
		weaponScore += effects[i].second;
	}
	if (type == HandleTypes::oneHanded) {
		weaponScore *= 0.75;
	}
	else if (type == HandleTypes::twoHanded) {
		weaponScore *= 1.5;
	}
	return weaponScore;
}

int Weapon::checkType(string newName)
{
	if (newName == "axe") {
		type = HandleTypes::oneHanded;
		return 1;
	}
	else if (newName == "sword") {
		type = HandleTypes::oneHanded;
		return 1;
	}
	else if (newName == "dagger") {
		type = HandleTypes::oneHanded;
		return 1;
	}
	else if (newName == "staff") {
		type = HandleTypes::twoHanded;
		return 2;
	}
	else if (newName == "mace") {
		type = HandleTypes::oneHanded;
		return 1;
	}

	return 1;

}

void Weapon::print()
{
	int size = effects.size();
	for (int i = 0; i < size; i++) {
		cout << effects[i].first << ' ' << effects[i].second << "\n";
	}
}

Weapon::Weapon()
{
	weaponKind = "axe";
	slots += checkType("axe");
}

Weapon::Weapon(HandleTypes newType, string newWeaponKind, double minDamage, double maxDamage)
{
	this->type = newType;
	this->weaponKind = newWeaponKind;
	slots += checkType(newWeaponKind);
	hitDamage.first = minDamage;
	hitDamage.second = maxDamage;
}


HandleTypes Weapon::getType() const
{
	return type;
}

string Weapon::getWeaponKind() const
{
	return weaponKind;
}

int Weapon::getSlots() const
{
	return slots;
}

void Weapon::changeWeaponKind(string newWeaponKind)
{
	slots += checkType(newWeaponKind);
	slots -= checkType(weaponKind);
	this->weaponKind = newWeaponKind;
}

void Weapon::changeHandleTypes(HandleTypes newType)
{
	this->type = newType;
}

void Weapon::addEffect(string newName, double newPower)
{
	if (newPower < 0) {
		cout << "Cannot be added" << endl;
		return;
	}

	if (changePowerEffect(newName, newPower)) {
		return;
	}

	effects.push_back(make_pair(newName, newPower));
}

void Weapon::removeEffect(string wantedToRemove)
{
	int index = -1;
	int size = effects.size();
	for (int i = 0; i < size; i++) {
		if (effects[i].first == wantedToRemove) {
			index = i;
			break;
		}
	}
	if (index == -1) {
		cout << "No effect to remove" << endl;
	}
	else {
		effects.erase(effects.begin() + index);
	}
}

bool Weapon::changePowerEffect(string name, double newPower)
{
	int size = effects.size();
	for (int i = 0; i < size; i++) {
		if (effects[i].first == name) {
			effects[i].second = newPower;
			return true;
		}
	}
	return false;
}
