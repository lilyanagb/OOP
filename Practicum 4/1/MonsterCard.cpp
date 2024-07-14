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

MonsterCard::MonsterCard(const string& newName, const string& newEffect, const unsigned int newRarity,const unsigned int newAttackingPoints,const unsigned int newProtectivePoints)
	: Card(newName, newEffect, newRarity), attackingPoints(newAttackingPoints), protectivePoints(newProtectivePoints)
{
}

void MonsterCard::setAttackingPoints(const unsigned int newAttackingPoints)
{
	attackingPoints = newAttackingPoints;
}

void MonsterCard::setProtectivePoints(const unsigned int newProtectivePoints)
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

Card* MonsterCard::copy() const
{
	return new MonsterCard(*this);
}

void MonsterCard::writeToFile(ostream& out) const
{
	out << *this;
}

ostream& operator<<(ostream& out, const MonsterCard& cards)
{
    out << cards.getName() << "|" << cards.getEffect() << "|" << cards.getRarity() << "|";
	out << cards.getAttackingPoints() << "|" << cards.getProtectivePoints()<<endl;
	return out;
}

istream& operator>>(istream& in, MonsterCard& cards)
{
	string myLine;
	getline(in, myLine);
	vector<string> line = Card::split(myLine, "|");

	string nameV, effectV;
	unsigned int rarityV = 0, attackingV = 0, protectiveV = 0;
	
	nameV = line[0];
	effectV = line[1];
	rarityV = stoi(line[2]);
	attackingV = stoi(line[3]);
	protectiveV = stoi(line[4]);

	cards.setName(nameV);
	cards.setEffect(effectV);
	cards.setRarity(rarityV);
	cards.setAttackingPoints(attackingV);
	cards.setProtectivePoints(protectiveV);
	return in;
}

