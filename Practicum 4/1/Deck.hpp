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
#include <algorithm>    
#include <random>         
#include <sstream>

class Deck
{
private:
	string name;
	vector<Card*> cards;

	void copyOther(const Deck&);
public:
	Deck()=default;
	Deck(const Deck&);
	Deck& operator=(const Deck&);
	~Deck();

	void setDeckname(const string&);
	string getDeckname() const;

	vector<Card*> getVector() const;

	unsigned int getCountOfMonsters() const;
	unsigned int getCountOfMagics() const; 
	unsigned int getCountOfPendulums() const;
	unsigned int getCountOfCards() const;

	void addCard(Card*);
	void changeCardInDeck(const unsigned int, Card*);
	void removeCardsFromDeck();
	void shuffle();

	friend ostream& operator<<(ostream& out, const Deck& cards);
	friend istream& operator>>(istream& in, Deck& cards);
};

