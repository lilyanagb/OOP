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
#include <iostream>

enum  magicCardType {
	trap,
	buff,
	spell
};

class magicCard {
public:
	void setName(char*);
	void setEffect(char*);
	void setCardType(magicCardType);

	 char* getName() const;
	 char* getEffect() const;
	magicCardType getCardType() const;

	magicCard();
	magicCard(char*,char*, magicCardType);
private:
	char* name;
	char* effect;
	magicCardType type;


};
