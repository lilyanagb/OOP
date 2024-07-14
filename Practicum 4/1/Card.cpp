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

Card::Card(const string& newName, const string& newEffect,const unsigned int newRarity)
{
    name = newName;
    effect = newEffect;
    rarity = newRarity;
}

void Card::setName(const string& newName)
{
    name = newName;
}

void Card::setEffect(const string& newEffect)
{
    effect = newEffect;
}

void Card::setRarity(const unsigned int newRarity)
{
    rarity = newRarity;
}

string Card::getName() const
{
    return name;
}

string Card::getEffect() const
{
    return effect;
}

unsigned int Card::getRarity() const
{
    return rarity;
}

bool Card::operator<(const Card& rhs) const
{
    return this->rarity < rhs.rarity;
}

bool Card::operator>(const Card& rhs) const
{
    return this->rarity > rhs.rarity;
}

vector<string> Card::split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;

    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());

    return tokens;
}

ostream& operator<<(ostream& out, const Card& cards)
{
    cards.writeToFile(out);
    return out;
}
