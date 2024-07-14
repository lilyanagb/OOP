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
	MagicCard() = default;

	void setCardType(CardType);

	CardType getCardType() const;

	MagicCard(string, string, CardType);
};

