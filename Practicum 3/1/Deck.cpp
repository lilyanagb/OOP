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

#include "Deck.hpp"

Deck::Deck()
{
	name = "";
}

void Deck::setDeckname(string newName)
{
	name = newName;
}

string Deck::getDeckname() const
{
	return name;
}

unsigned int Deck::returnMagicCards()
{
	return magicCards.size();
}

unsigned int Deck::returnMonsterCards()
{
	return monsterCards.size();
}

unsigned int Deck::returnPendulumCards()
{
	return pendulumCards.size();
}

void Deck::addMagicCard(const MagicCard& card)
{
	magicCards.push_back(card);
}

void Deck::addMonsterCard(const MonsterCard& card)
{
	monsterCards.push_back(card);
}

void Deck::addPendulumCard(const PendulumCard& card)
{
	pendulumCards.push_back(card);
}

void Deck::changeMagicToDeck(int index, const MagicCard& card)
{
	if (index == magicCards.size()) {
		cout << "No card of this index" << endl;
		return;
	}
	magicCards.at(index) = card;
}

void Deck::changeMonsterToDeck(int index, const MonsterCard& card)
{
	if (index == monsterCards.size()) {
		cout << "No card of this index" << endl;
		return;
	}
	monsterCards.at(index) = card;
}

void Deck::changePendulumToDeck(int index, const PendulumCard& card)
{
	if (index == pendulumCards.size()) {
		cout << "No card of this index" << endl;
		return;
	}
	pendulumCards.at(index) = card;
}

void Deck::removeCardsFromDeck()
{
	magicCards.clear();
	monsterCards.clear();
	pendulumCards.clear();
}

vector<MonsterCard> Deck::getMonsterVector() const
{
	return monsterCards;
}

vector<MagicCard> Deck::getMagicVector() const
{
	return magicCards;
}

vector<PendulumCard> Deck::getPendulumVector() const
{
	return pendulumCards;
}

