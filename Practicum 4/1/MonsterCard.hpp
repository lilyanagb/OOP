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
	MonsterCard(const string& = "", const string& = "",const unsigned int = 0,const unsigned int = 0,const unsigned int = 0);

	void setAttackingPoints(const unsigned int);
	void setProtectivePoints(const unsigned int);

	unsigned int getAttackingPoints() const;
	unsigned int getProtectivePoints() const;

	friend ostream& operator<<(ostream& out, const MonsterCard& cards);
	friend istream& operator>>(istream& in, MonsterCard& cards);

	void writeToFile(ostream& out) const override;
	Card* copy() const override;
};

