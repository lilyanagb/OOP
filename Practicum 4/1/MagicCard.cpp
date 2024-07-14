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

MagicCard::MagicCard(const string& newName, const string& newEffect,const unsigned int newRarity, CardType newType)
    : Card(newName,newEffect,newRarity), type(newType)
{
}

void MagicCard::setCardType(CardType newType)
{
    type = newType;
}

CardType MagicCard::getCardType() const
{
    return type;
}

Card* MagicCard::copy() const
{
    return new MagicCard(*this);
}

void MagicCard::writeToFile(ostream& out) const
{
    out << *this;
}

ostream& operator<<(ostream& out, const MagicCard& cards)
{
    out << cards.getName() << "|" << cards.getEffect() << "|" << cards.getRarity() << "|";
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

istream& operator>>(istream& in, MagicCard& cards)
{
    string myLine;
    getline(in, myLine);
    vector<string> line = Card::split(myLine, "|");
    int trashCount = line.size() - 1;
  
    string nameV, effectV,typeV;
    unsigned int rarityV = 0;

    nameV = line[0];
    effectV = line[1];
    rarityV = stoi(line[2]);
    typeV = line[3];

    cards.setName(nameV);
    cards.setEffect(effectV);
    cards.setRarity(rarityV);
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
