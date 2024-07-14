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
#include "MonsterCard.hpp"
#include "MagicCard.hpp"

class PendulumCard : public MonsterCard, public MagicCard
{
private:
	unsigned int pendulumScale;

public:
	PendulumCard();

	void setPendulumScale(unsigned int);

	unsigned int getPendulumScale() const;

	PendulumCard(string, string, unsigned int, unsigned int, unsigned int, CardType);
};

