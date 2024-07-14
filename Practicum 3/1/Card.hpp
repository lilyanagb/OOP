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
#include <string>
#include <iostream>
using namespace std;

class Card
{
private:
	string name;
	string effect;
public:
	Card();
	Card(string, string);

	void setName(string);
	void setEffect(string);

	string getName() const;
	string getEffect() const;
};

