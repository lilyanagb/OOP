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

#include "Money.hpp"
#include <iostream>
using namespace std;

Money::Money()
{
	gold = 0;
	silver = 0;
}

int Money::getSlots() const
{
	return 0;
}

void Money::setSilverCount(int newSilver)
{
	this->silver += newSilver;
}

int Money::getSilver() const
{
	return silver;
}

void Money::setGoldCount(int newGold)
{
	this->gold += newGold;
}

int Money::getGold() const
{
	return gold;
}

void Money::count()
{
	if (this->silver >= 100) {
		this->gold += silver / 100;
		if (gold > 99) {
			cout << "It is max" << endl;
			return;
		}
		this->silver = silver % 100;
	}
}

void Money::print()
{
	cout << "gold: " << this->gold << ' ' << "silver: " << this->silver << endl;
}


