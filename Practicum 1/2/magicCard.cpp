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

#include "magicCard.h"

void magicCard::setName(char* newName)
{
    int i = 0;
    while (newName[i] != '\0') {
        i++;
    }
    name = new char[i + 1];
    for (int j = 0; j < i; j++) {
        name[j] = newName[j];
    }
    name[i] = '\0';
}

void magicCard::setEffect(char* newEffect)
{
    int i = 0;
    while (newEffect[i] != '\0') {
        i++;
    }
    effect = new char[i + 1];
    for (int j = 0; j < i; j++) {
        effect[j] = newEffect[j];
    }
    effect[i] = '\0';
}

void magicCard::setCardType(magicCardType type)
{
    this->type = type;
}

 char* magicCard::getName() const
{
    return name;
}

 char* magicCard::getEffect() const
{
    return effect;
}

magicCardType magicCard::getCardType() const
{
    return type;
}

magicCard::magicCard()
{
    this->type = magicCardType::trap;
    this->name=nullptr;
    this->effect=nullptr;
}

magicCard::magicCard(char* newName, char* newEffect, magicCardType type)
{
    setName(newName);
    setEffect(newEffect);
    setCardType(type);
}


