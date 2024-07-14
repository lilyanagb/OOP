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

#include "MonsterCard.hpp"

MonsterCard::MonsterCard()
{
	attackingPoints = 0;
	protectivePoints = 0;
}

void MonsterCard::setAttackingPoints(unsigned int newAttackingPoints)
{
	attackingPoints = newAttackingPoints;
}

void MonsterCard::setProtectivePoints(unsigned int newProtectivePoints)
{
	protectivePoints = newProtectivePoints;
}

unsigned int MonsterCard::getAttackingPoints() const
{
	return attackingPoints;
}

unsigned int MonsterCard::getProtectivePoints() const
{
	return protectivePoints;
}

MonsterCard::MonsterCard(string newName, string newEffect, unsigned int newAttackingPoints, unsigned int newProtectivePoints) 
	: Card(newName, newEffect), attackingPoints(newAttackingPoints), protectivePoints(newProtectivePoints)
{
}
