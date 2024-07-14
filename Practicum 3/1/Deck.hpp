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
#include "PendulumCard.hpp"
#include <vector>

class Deck
{
protected:
	string name;

	vector<MonsterCard> monsterCards;
	vector<MagicCard> magicCards;
	vector<PendulumCard> pendulumCards;

public:
	Deck();

	void setDeckname(string);
	string getDeckname() const;

	unsigned int returnMagicCards();
	unsigned int returnMonsterCards();
	unsigned int returnPendulumCards();
	void addMagicCard(const MagicCard&);
	void addMonsterCard(const MonsterCard&);
	void addPendulumCard(const PendulumCard&);
	void changeMagicToDeck(int, const MagicCard&);
	void changeMonsterToDeck(int, const MonsterCard&);
	void changePendulumToDeck(int, const PendulumCard&);
	void removeCardsFromDeck();

	vector<MonsterCard> getMonsterVector() const;
	vector<MagicCard> getMagicVector() const;
	vector<PendulumCard> getPendulumVector() const;
};

