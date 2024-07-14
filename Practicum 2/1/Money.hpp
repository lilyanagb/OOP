/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021 *
* @author Lilyana Belcheva
* @idnumber 62599
* @task 1
* @compiler VC
*/

#pragma once

class Money
{
private:
	int gold;
	int silver;
public:
	Money();
	int getSlots() const;

	void setSilverCount(int);
	int getSilver() const;
	void setGoldCount(int);
	int getGold() const;

	void count();
	void print();
};

