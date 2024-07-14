/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Lilyana Belcheva
* @idnumber 62599
* @task 2
* @compiler VC
*/


#include "deck.h"
#include <iostream>

using namespace std;

deck::deck()
{
	countOfMonsterCards = 0;
	countOfMagicCards = 0;
}

int deck::returnMagicCards()
{
	return countOfMagicCards;
}

int deck::returnMonsterCards()
{
	return countOfMonsterCards;
}

void deck::addMagicToDeck()
{
	if (countOfMagicCards == 20) {
		cout << "Cannot be added" << endl;
		return;
	}

	char* name = new char[25];
	char* effect = new char[100];
	magicCardType type{};

	cin >> name;
	cin >> effect;
	cout << "Please enter magic card type:\n\t0 - trap\n\t1 - buff\n\t2 - spell\n";
	unsigned int choice = 0;
	cin >> choice;

	if (choice < 0 || choice >= 3) {
		cout << "Wrong input" << endl;
	}
	else if (choice == 0) {
		type = magicCardType::trap;
	}
	else if (choice == 1) {
		type = magicCardType::buff;
	}
	else if (choice == 2) {
		type = magicCardType::spell;
	}


	for (int i = 0; i < 20; i++) {
		if (usedMagicCards[i] != 1) {
			magicCards[i].setName(name);
			magicCards[i].setEffect(effect);
			magicCards[i].setCardType(type);
			countOfMagicCards++;
			usedMagicCards[i] = 1;
			return;
		}
	}
}

void deck::addMonsterToDeck()
{
	char* name=new char[25];
	if (countOfMonsterCards == 20) {
		cout << "Cannot be added" << endl;
		return;
	}
	int attackingPoints;
	int protectivePoints;
	cin >> name;
	cin >> attackingPoints >> protectivePoints;
	for (int i = 0; i < 20; i++) {
		if (usedMonsterCards[i] != 1) {
			monsterCards[i].setName(name);
			monsterCards[i].setAttackingPoints(attackingPoints);
			monsterCards[i].setProtectivePoints(protectivePoints);
			countOfMonsterCards++;
			return;
		}
	}
}

void deck::changeMagicToDeck(int index, const magicCard& card)
{
		usedMagicCards[index] = 1;
		magicCards[index] = card;
		countOfMagicCards++;
}

void deck::changeMonsterToDeck(int index, const monsterCard& card)
{
	if (usedMonsterCards[index] != 0) {
		cout << "Cannot be added" << endl;
	}
	else {
		usedMonsterCards[index] = 1;
		monsterCards[index] = card;
	    countOfMonsterCards++;
	}
}

void deck::print() const
{
	for (int i = 0; i < 20; i++) {
		if (usedMonsterCards[i] != 0) {
			cout << monsterCards[i].getName() << " ";
			cout << monsterCards[i].getAttackingPoints() << " ";
			cout << monsterCards[i].getProtectivePoints()<<endl;
		}
	}
	for (int i = 0; i < 20; i++) {
		if (usedMagicCards[i] != 0) {
			cout << magicCards[i].getName()<<" ";
			cout << magicCards[i].getEffect() << " ";
			cout << magicCards[i].getCardType()<<endl;
		}
	}
	
}
