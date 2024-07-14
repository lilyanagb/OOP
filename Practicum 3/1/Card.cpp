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

#include "Card.hpp"

Card::Card()
{
    this->name = "";
    this->effect ="";
}

Card::Card(string newName, string newEffect)
{
    name = newName;
    effect = newEffect;
}

void Card::setName(string newName)
{
    name = newName;
}

void Card::setEffect(string newEffect)
{
    effect = newEffect;
}

string Card::getName() const
{
    return name;
}

string Card::getEffect() const
{
    return effect;
}
