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

#include "monsterCard.h"

void monsterCard::setName(char* newName)
{
    int i = 0;
    while (newName[i] != '\0'){
        i++;
   }
    name = new char[i + 1];
    for (int j = 0; j < i; j++) {
        name[j] = newName[j];
    }
    name[i] = '\0';
}

void monsterCard::setAttackingPoints(unsigned int attackingPoints)
{
    this->attackingPoints = attackingPoints;
}

void monsterCard::setProtectivePoints(unsigned int protectivePoints)
{
    this->protectivePoints = protectivePoints;
}

 char* monsterCard::getName() const
{
    return name;
}

int monsterCard::getAttackingPoints() const
{
    return this->attackingPoints;
}

int monsterCard::getProtectivePoints() const
{
    return this->protectivePoints;
}

monsterCard::monsterCard()
{
    this->name = nullptr;
    this->attackingPoints = 0;
    this->protectivePoints = 0;
}

monsterCard::monsterCard(char* newName, unsigned int attackingPoints, unsigned int protectivePoints)
{
    setName(newName);
    this->attackingPoints = attackingPoints;
    this->protectivePoints = protectivePoints;
}


