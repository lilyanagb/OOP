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

#include "Date.h"
#include <iostream>
using namespace std;

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 2000;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	setDay(day);
	setMonth(month);
	this->year = year;
}

void Date::setDay(unsigned int day)
{
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) ||
		(month == 8) || (month == 10) || (month == 12))
	{
		if (day > 31) {
			cout << "The day is invalid" << endl;
			return;
		}
	}
	else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
	{
		if (day > 30) {
			cout << "The day is invalid" << endl;
			return;
		}
	}
	else if ((month == 2) && yearCheck(year))
	{
		if (day > 29) {
			cout << "The day is invalid" << endl;
			return;
		}
	}
	else if ((month == 2) && !yearCheck(year))
	{
		if (day > 28) {
			cout << "The day is invalid" << endl;
			return;
		}
	}
	
		this->day = day;
}

void Date::setMonth(unsigned int month)
{
	if (month < 1 || month > 12) {
		cout << "The month is invalid" << endl;
		return;
	}
	else {
		this->month = month;
	}
}

void Date::setYear(unsigned int year)
{
	this->year = year;
}

int Date::getDay() const
{
	return this->day;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getYear() const
{
	return this->year;
}

void Date::addDays(int n)
{
	int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	this->day += n;

	while (this->day > daysPerMonth[this->month]) {
		daysInFebruary(daysPerMonth);

		this->day -= daysPerMonth[this->month];
		this->month++;
		if (this->month > 12) {
			this->month = 1;
			this->year++;
		}
	}
}

void Date::removeDays(int n)
{
	int daysPerMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	//check if the date is in the current month
	if (this->day > n) {
		this->day -= n;

	}
	else {
		daysInFebruary(daysPerMonth);
		int daysLeft = this->day - n; //negative number with the difference

		while (daysLeft <= 0) {
			this->month--;

			if (this->month < 1) {
				this->month = 12;
				this->year -= 1;
				daysInFebruary(daysPerMonth);
			}

			this->day = daysLeft + daysPerMonth[this->month];
			daysLeft += daysPerMonth[this->month];

			if (this->day == 0) {
				this->month--;
				this->day = daysPerMonth[this->month];
			}

		}
	}
}

bool Date::isLeapYear()
{
	if (((this->year % 4 == 0) && (this->year % 100 != 0)) || (this->year % 400 == 0)) {
		return true;
	}
	return false;
}

int Date::daysToChristmas()
{
	int daysPerMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	const int XmasDay = 25;
	const int XmasMonth = 12;

	daysInFebruary(daysPerMonth);
	int daysLeft = daysPerMonth[this->month] - day;

	if (month == XmasMonth) {
		if (day >= XmasDay) {
			this->year++;
			this->day = 1;
			this->month = 1;
			daysInFebruary(daysPerMonth);
		}
		else {
			return XmasDay - this->day;
		}
	}
	else {
		this->month++;
	}

	while (this->month != XmasMonth) {
		daysLeft += daysPerMonth[this->month];
		this->month++;
	}
	daysLeft += XmasDay;
	return daysLeft;
}

int Date::daysToNewYear()
{
	int daysPerMonth[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	const int NewYearDay = 31;
	const int NewYearMonth = 12;

	daysInFebruary(daysPerMonth);
	int daysLeft = daysPerMonth[this->month] - this->day;

	if (month == NewYearMonth) {
		if (day >= NewYearDay) {
			this->year++;
			this->day = 1;
			this->month = 1;
			daysInFebruary(daysPerMonth);
		}
		else {
			return daysLeft;
		}
	}
	else {
		this->month++;
	}

	while (this->month != NewYearMonth) {

		daysLeft += daysPerMonth[this->month];
		this->month++;

	}
	//add +1 for 01.01.XXXXX
	daysLeft += NewYearDay + 1;

	return daysLeft;
}

int Date::daysToEvent(const Date& event) {
	int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int n1Year = this->year;
	int n2Year = event.year;
	int n1 = n1Year * 365 + this->day;

	while (n1Year != 0) {
		if (yearCheck(n1Year)) {
			n1 += 1;
		}
		n1Year--;
	}
	if (yearCheck(this->year)) {
		daysInFebruary(daysPerMonth);
	}
	for (int i = 1; i < this->month; i++) {
		n1 += daysPerMonth[i];
	}

	int n2 = n2Year * 365 + event.day;
	while (n2Year != 0) {
		if (yearCheck(n2Year)) {
			n2 += 1;
		}
		n2Year--;
	}
	if (yearCheck(event.year)) {
		daysInFebruary(daysPerMonth);
	}
	for (int i = 1; i < event.month; i++) {
		n2 += daysPerMonth[i];
	}

	if (n1 > n2) {
		return n1 - n2;
	}
	return n2 - n1;
}

bool Date::isLaterThen(const Date& other)
{
	if (other.year > this->year) {
		return true;
	}
	else if (other.year == this->year) {
		if (other.month > this->month) {
			return true;
		}
		else if (other.month == this->month) {
			if (other.day > this->day) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}

void Date::printDay() const
{
	if (this->day < 10) {
		cout << "0" << this->day;
	}
	else {
		cout << this->day;
	}
	cout << ".";
}

void Date::printMonth() const
{
	if (this->month < 10) {
		cout << "0" << this->month;
	}
	else {
		cout << this->month;
	}
	cout << ".";
}

bool Date::yearCheck(int year)
{
	//same function as isLeapYear() but accepts parameter
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) {
		return true;
	}
	return false;
}

void Date::daysInFebruary(int* daysPerMonth)
{
	if (isLeapYear()) {
		daysPerMonth[2] = 29;
	}
	else {
		daysPerMonth[2] = 28;
	}
}

void Date::print() const
{
	printDay();
	printMonth();
	cout << this->year << endl;
}

