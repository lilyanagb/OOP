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

enum class CardType {
	TRAP,
	BUFF,
	SPELL
};

class MagicCard : virtual public Card
{
private:
	CardType type;

public:
	MagicCard(const string& = "", const string& ="",const unsigned int =0, CardType=CardType::TRAP);

	void setCardType(CardType);

	CardType getCardType() const;

	friend ostream& operator<<(ostream& out, const MagicCard& cards);
	friend istream& operator>>(istream& in, MagicCard& cards);

	void writeToFile(ostream& out) const override;
	Card* copy() const override;
};

