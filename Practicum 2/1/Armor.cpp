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

#include "Armor.hpp"
#include <iostream>
using namespace std;


Armor::Armor()
{
	type = ArmorTypes::cloth;
	defense = 0;
	setSlots(1);
}

Armor::Armor(ArmorTypes newType, int newDefense)
{
	setSlots(1);
	this->type = newType;
	this->defense = newDefense;
}

void Armor::setSlots(int newSlot)
{
	slots += newSlot;
}

void Armor::setType(ArmorTypes newType)
{
	this->type = newType;
}

void Armor::setDefense(int newDefense)
{
	this->defense = newDefense;
}

ArmorTypes Armor::getType() const
{
	return type;
}

int Armor::getDefense() const
{
	return defense;
}

int Armor::getSlots() const
{
	return slots;
}

double Armor::getGearscore()
{
	double gearscore = 0;
	int size = effects.size();
	for (int i = 0; i < size; i++) {
		gearscore += effects[i].second;
	}
	return gearscore;
}

void Armor::addEffect(string newName, double newPower)
{
	if (newPower < 0) {
		cout << "Cannot be added" << endl;
		return;
	}

	if (changeEffect(newName, newPower)) {
		return;
	}
	effects.push_back(make_pair(newName, newPower));

}

void Armor::removeEffect(string wantedToRemove)
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

bool Armor::changeEffect(string name, double newPower)
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

void Armor::print()
{
	int size = effects.size();
	for (int i = 0; i < size; i++) {
		cout << effects[i].first << ' ' << effects[i].second << "\n";
	}
}

