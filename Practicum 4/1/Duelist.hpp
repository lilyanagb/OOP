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
#include "Deck.hpp"
#include <fstream>

class Duelist
{
private:
	string name;
	Deck deck;

public:
	Duelist(const string&);

	Deck& getDeck();
	bool saveDeck(const char* filename);
	bool loadDeck(const char* filename);
	void duel(Duelist&);
};

