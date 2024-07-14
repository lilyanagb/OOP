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
	PendulumCard(const string& = "", const string & = "", const unsigned int =0, const unsigned int = 0, const unsigned int = 0, const unsigned int = 1, CardType = CardType::TRAP);

	void setPendulumScale(const unsigned int);

	unsigned int getPendulumScale() const;

	friend ostream& operator<<(ostream& out, const PendulumCard& cards);
	friend istream& operator>>(istream& in, PendulumCard& cards);

	void writeToFile(ostream& out) const override;
	Card* copy() const override;
};

