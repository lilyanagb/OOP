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

#include "PendulumCard.hpp"

PendulumCard::PendulumCard()
{
	pendulumScale = 0;
}

void PendulumCard::setPendulumScale(unsigned int scale)
{
	if (scale < 1 || scale>13) {
		pendulumScale = 0;
		return;
	}
	pendulumScale = scale;
}

unsigned int PendulumCard::getPendulumScale() const
{
	return pendulumScale;
}

PendulumCard::PendulumCard(string newName, string newEffect, unsigned int newAttackingPoints, unsigned int newProtectivePoints, unsigned int scale, CardType newType)
	:Card(newName, newEffect),
	MonsterCard(newName, newEffect, newAttackingPoints, newProtectivePoints),
	MagicCard(newName, newEffect, newType),
	pendulumScale(scale)
{
}


