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

#include "PendulumCard.hpp"

void PendulumCard::setPendulumScale(const unsigned int newScale)
{
    pendulumScale = newScale;
}

unsigned int PendulumCard::getPendulumScale() const
{
    return pendulumScale;
}

PendulumCard::PendulumCard(const string& newName, const string& newEffect, const unsigned int newRarity, const unsigned int newAttackingPoints,const unsigned int newProtectivePoints, unsigned int newPendulumScale, CardType newType)
    : Card(newName,newEffect,newRarity),
    MonsterCard(newName, newEffect, newRarity, newAttackingPoints, newProtectivePoints),
    MagicCard(newName, newEffect, newRarity, newType),
    pendulumScale(newPendulumScale)
{
}

Card* PendulumCard::copy() const
{
    return new PendulumCard(*this);
}


void PendulumCard::writeToFile(ostream& out) const
{
    out << *this;
}

ostream& operator<<(ostream& out, const PendulumCard& cards)
{
    out << cards.getName() << "|" << cards.getEffect() << "|" << cards.getRarity() << "|";
    out << cards.getAttackingPoints() << "|" << cards.getProtectivePoints() << "|" << cards.getPendulumScale()<<"|";
    if (cards.getCardType() == CardType::BUFF) {
        out << "BUFF" << "\n";
    }
    else if (cards.getCardType() == CardType::SPELL) {
        out << "SPELL" << "\n";
    }
    else if (cards.getCardType() == CardType::TRAP) {
        out << "TRAP" << "\n";
    }
    return out;
}

istream& operator>>(istream& in, PendulumCard& cards)
{
    string myLine;
    getline(in, myLine);
    vector<string> line = Card::split(myLine, "|");
    int trashCount = line.size() - 1; 

    string nameV, effectV, typeV;
    unsigned int rarityV = 0, attackingV = 0, protectiveV = 0, scaleV=0;
   
    nameV = line[0];
    effectV = line[1];
    rarityV = stoi(line[2]);
    attackingV = stoi(line[3]);
    protectiveV = stoi(line[4]);
    scaleV = stoi(line[5]);
    typeV = line[6];

    cards.setName(nameV);
    cards.setEffect(effectV);
    cards.setRarity(rarityV);
    cards.setAttackingPoints(attackingV);
    cards.setProtectivePoints(protectiveV);
    if (typeV == "TRAP") {
        cards.setCardType(CardType::TRAP);
    }
    else if (typeV == "BUFF") {
        cards.setCardType(CardType::BUFF);
    }
    else if (typeV == "SPELL") {
        cards.setCardType(CardType::SPELL);
    }
    return in;
}
