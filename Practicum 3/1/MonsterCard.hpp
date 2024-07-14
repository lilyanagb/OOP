/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Lilyana Belcheva
* @idnumber 62599
* @task 1
* @compiler VC
*/

#pragma once
#include "Card.hpp"

class MonsterCard : virtual public Card
{
private:
	unsigned int attackingPoints;
	unsigned int protectivePoints;
public:
	MonsterCard();

	void setAttackingPoints(unsigned int);
	void setProtectivePoints(unsigned int);

	unsigned int getAttackingPoints() const;
	unsigned int getProtectivePoints() const;

	MonsterCard(string, string, unsigned int, unsigned int);
};

