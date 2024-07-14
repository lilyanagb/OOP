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

void Deck::copyOther(const Deck& other)
{
	for (auto card : other.cards)
	{
		cards.push_back(card->copy());
	}
}

Deck::Deck(const Deck& rhs)
{
	copyOther(rhs);
}

Deck& Deck::operator=(const Deck& rhs)
{
	if (this != &rhs) {
		removeCardsFromDeck();
		copyOther(rhs);
	}
	return *this;
}

Deck::~Deck()
{
	removeCardsFromDeck();
}

void Deck::setDeckname(const string& newName)
{
	name = newName;
}

string Deck::getDeckname() const
{
	return name;
}

 vector<Card*> Deck::getVector() const
{
	return cards;
}

unsigned int Deck::getCountOfMonsters() const
{
	int count = 0;
	for (auto monsters : cards) {
		auto monsterPtr = dynamic_cast<MonsterCard*>(monsters);
		auto magicPtr = dynamic_cast<MagicCard*>(monsters);
		if (monsterPtr) {
			if (magicPtr) {
				continue;
			}
			count++;
		}
	}
	return count;
}

unsigned int Deck::getCountOfMagics() const
{
	int count = 0;
	for (auto magics : cards) {
		auto magicPtr = dynamic_cast<MagicCard*>(magics);
		auto monsterPtr = dynamic_cast<MonsterCard*>(magics);
		if (magicPtr) {
			if (monsterPtr) {
				continue;
			}
			count++;
		}
	}
	return count;
}

unsigned int Deck::getCountOfPendulums() const
{
	int count = 0;
	for (auto pendulums : cards) {
		auto pendulumPtr = dynamic_cast<PendulumCard*>(pendulums);
		if (pendulumPtr) {
			count++;
		}
	}
	return count;
}

unsigned int Deck::getCountOfCards() const
{
	return cards.size();
}

void Deck::addCard(Card* newCard)
{
	cards.push_back(newCard->copy());
}

void Deck::changeCardInDeck(const unsigned int index, Card* newCard)
{
	if (index >= cards.size()) {
		cout << "No card of this index" << endl;
		return;
	}

	PendulumCard* pendulum = dynamic_cast<PendulumCard*>(newCard);
	if (pendulum)
	{
		cards.at(index) = newCard->copy();
		return;
	}

	MonsterCard* monster = dynamic_cast<MonsterCard*>(newCard);
	if (monster)
	{
		cards.at(index) = newCard->copy();
		return;
	}

	MagicCard* magic = dynamic_cast<MagicCard*>(newCard);
	if (magic)
	{
		cards.at(index) = newCard->copy();
		return;
	}
}

void Deck::removeCardsFromDeck()
{
	name = "";
	for (int i = 0; i < cards.size(); i++) {
		delete cards[i];
	}

	cards.clear();
}

void Deck::shuffle()
{
	int size = getCountOfCards();
	for (int i = 0; i < size - 1; i++) {
		int j = i + rand() % (size - i);
		swap(cards[i], cards[j]);
	}
}

ostream& operator<<(ostream& out, const Deck& element)
{
	for (auto elements : element.cards) {
		auto pendulumPtr = dynamic_cast<PendulumCard*>(elements);
		if (pendulumPtr) {
			out << elements;
			break;
		}
		auto monsterPtr = dynamic_cast<MonsterCard*>(elements);
		if (monsterPtr) {
			out << elements;
			break;
		}
		auto magicPtr = dynamic_cast<MagicCard*>(elements);
		if (magicPtr) {
			out << elements;
		}
	}
	return out;
}

istream& operator>>(istream& in, Deck& element)
{
	string myLine;
	char trash;
	unsigned int countOfCards = 0, countOfMonsters = 0, countOfMagics = 0, countOfPendulums = 0;
	getline(in, myLine, '|');
	element.setDeckname(myLine);
	in >> countOfCards >> trash >> countOfMonsters >> trash >> countOfMagics >> trash >> countOfPendulums;

	
	while (getline(in, myLine)) {
		vector<string> line = Card::split(myLine, "|");
		int trashCount = line.size() - 1;  

		istringstream is(myLine);
		if (trashCount == 4) {
			MonsterCard* to_add = new MonsterCard();
			is >> *to_add;
			element.addCard(to_add);
		}
		else if (trashCount == 3) {
			MagicCard* to_add = new MagicCard();
			is >> *to_add;
			element.addCard(to_add);
		}
		else if (trashCount == 6) {
			PendulumCard* to_add = new PendulumCard();
			is >> *to_add;
			element.addCard(to_add);
		}
	}
		return in;
}
