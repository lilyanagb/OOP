/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Lilyana Belcheva
* @idnumber 62599
* @task 2
* @compiler VC
*/

#include "duelist.h"

const char* duelist::getName() const
{
    return name;
}

const deck* duelist::getDeck() const
{
    return &Deck;
}

int duelist::returnMagicCards()
{
    return Deck.returnMagicCards();
}

int duelist::returnMonsterCards()
{
    return Deck.returnMonsterCards();
}

void duelist::addMagic()
{
    Deck.addMagicToDeck();
}

void duelist::addMonster()
{
    Deck.addMonsterToDeck();
}

void duelist::changeMagic(int index, const magicCard& newCard)
{
Deck.changeMagicToDeck(index, newCard);
}

void duelist::addMonster(int index, const monsterCard& newCard)
{
    Deck.changeMonsterToDeck(index, newCard);
}
