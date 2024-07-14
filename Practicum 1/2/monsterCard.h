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

#pragma once
class monsterCard
{
public:
	void setName(char*);
	void setAttackingPoints(unsigned int);
	void setProtectivePoints(unsigned int);

    char* getName() const;
	int getAttackingPoints() const;
	int getProtectivePoints() const;

	monsterCard();
	monsterCard(char*, unsigned int, unsigned int);
private:
		char* name;
		unsigned int attackingPoints;
		unsigned int protectivePoints;
};

