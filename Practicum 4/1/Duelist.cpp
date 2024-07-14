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

#include "Duelist.hpp"
Duelist::Duelist(const string& newName)
{
	name = newName;
}

Deck& Duelist::getDeck()
{
	return deck;
}

bool Duelist::saveDeck(const char* filename)
{
	ofstream out;
	
	out.open(filename, ios_base::out | ios_base::trunc);
	if (!out) {
		cout << "Error in opening the output file" << endl;
		return false;
	}

	out << deck.getDeckname() << "|" << deck.getCountOfCards() << "|"
		<< deck.getCountOfMonsters() << "|" << deck.getCountOfMagics() << "|" << deck.getCountOfPendulums() << "\n";

	for (auto i: deck.getVector()) {
		out << *i;
	}

	return true;
}

bool Duelist::loadDeck(const char* filename)
{
	deck.removeCardsFromDeck();

	ifstream in;
	in.open(filename);
	if (!in) {
		cout << "Error in opening the file" << endl;
		return false;
	}
	else {
		in >> deck;
	}

	in.close();
	return true;
}

void Duelist::duel(Duelist& second)
{
	int pointsFirst = 0, pointsSecond = 0;
	if ((this->deck.getCountOfMonsters() != second.deck.getCountOfMonsters()) || 
		(this->deck.getCountOfMagics() != second.deck.getCountOfMagics()) ||
		(this->deck.getCountOfPendulums() != second.deck.getCountOfPendulums())) {
		cout << "Not equal number of cards" << endl;
		return;
	}

	this->deck.shuffle();
	second.deck.shuffle();

	for (int i = 0; i < this->deck.getCountOfCards();i++) {
			if (*this->deck.getVector()[i] > *second.deck.getVector()[i]) {
				pointsFirst++;
			}
			else if (*this->deck.getVector()[i] < *second.deck.getVector()[i]) {
				pointsSecond++;
			}
		}

	if (pointsFirst > pointsSecond) {
		cout << "First player wins the game" << endl;
	}
	else if (pointsFirst == pointsSecond) {
		cout << "The players have an equal number of points" << endl;
	}
	else {
		cout << "Second player wins the game" << endl;
	}
}
