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
#include "deck.h"
class duelist {
private:
	deck Deck;
	char* name;
public:
	const char* getName() const;
	const deck* getDeck() const;

	int returnMagicCards();
	int returnMonsterCards();
	void addMagic();
	void addMonster();
	void changeMagic(int,const magicCard&);
	void addMonster(int, const monsterCard&);
};

