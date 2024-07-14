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

#include "MagicCard.hpp"

void MagicCard::setCardType(CardType newType)
{
	type = newType;
}

CardType MagicCard::getCardType() const
{
	return type;
}

MagicCard::MagicCard(string newName, string newEffect, CardType newType)
	: Card(newName, newEffect), type(newType)
{
}
