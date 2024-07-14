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
#include <fstream>
#include <string>
#include <iostream>
#include<vector>
using namespace std;

class Card
{
private:
	string name;
	string effect;
	unsigned int rarity;

public:
	Card(const string& = "", const string& ="",const unsigned int =0);
	virtual ~Card() = default;

	void setName(const string&);
	void setEffect(const string&);
	void setRarity(const unsigned int);

	string getName() const;
	string getEffect() const;
	unsigned int getRarity() const;

	virtual bool operator< (const Card&) const;
	virtual bool operator> (const Card&) const;

	friend ostream& operator<<(ostream& out, const Card& cards);

	virtual Card* copy() const = 0;
	virtual void writeToFile(ostream& out) const = 0;
	static vector<string> split(const string&, const string&);
};

