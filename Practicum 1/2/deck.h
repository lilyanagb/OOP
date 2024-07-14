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

#pragma once
#include "magicCard.h"
#include "monsterCard.h"

class deck
{
public:
	deck();

	int returnMagicCards();
	int returnMonsterCards();
	void addMagicToDeck(); 
	void addMonsterToDeck();
	void changeMagicToDeck(int, const magicCard&);
	void changeMonsterToDeck(int, const monsterCard&);
	void print() const;
private:
	unsigned int countOfMonsterCards;
	unsigned int countOfMagicCards;
	bool usedMagicCards[20] = {0,};
	bool usedMonsterCards[20] = {0,};
	monsterCard monsterCards[20];
	magicCard magicCards[20];
};

