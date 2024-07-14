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
class Date
{
public:
	Date();
	Date(unsigned int, unsigned int, unsigned int);

	void setDay(unsigned int);
	void setMonth(unsigned int);
	void setYear(unsigned int);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void addDays(int);
	void removeDays(int);
	bool isLeapYear();
	int daysToChristmas();
	int daysToNewYear();
	int daysToEvent(const Date&);
	bool isLaterThen(const Date&);
	void print() const;

private:
	void printDay() const;
	void printMonth() const;
	bool yearCheck (int);
	void daysInFebruary(int*);

	unsigned int day;
	unsigned int month;
	unsigned int year;
};

