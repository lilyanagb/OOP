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
#include "Money.hpp"
#include "Materials.hpp"
#include <vector>
#include <iostream>
using namespace std;

template<class T>
class Backpack
{
private:
	int slots;
	vector<T> item;
public:
	Backpack();

	int getSlots() const;

	bool isEmpty();
	bool isFull();
	void clear();
	void add(T);
	void remove(T);

	void print();
};

template<class T>
inline Backpack<T>::Backpack()
{
	slots = 0;
}

template<class T>
inline int Backpack<T>::getSlots() const
{
	return slots;
}

template<class T>
inline bool Backpack<T>::isEmpty()
{
	if (slots == 0) {
		return true;
	}
	return false;
}

template<class T>
inline bool Backpack<T>::isFull()
{
	if (slots >= 16) {
		return true;
	}
	return false;
}

template<class T>
inline void Backpack<T>::clear()
{
	item.clear();
	slots = 0;
}

template<class T>
inline void Backpack<T>::add(T newItem)
{
	if (slots >= 16) {
		cout << "It is full" << endl;
		return;
	}

	item.push_back(newItem);
	slots += newItem.getSlots();
}

template<class T>
inline void Backpack<T>::remove(T wantedToRemove)
{
	return;
}

template<class T>
inline void Backpack<T>::print()
{
		int size = item.size();
		for (int i = 0; i < size; i++)
			item[i].print();
}

template<>
inline void Backpack<Money>::remove(Money wantedToRemove) {
	if (slots == 0) {
		cout << "It is empty" << endl;
		return;
	}

	for (int i = 0; i < slots; i++) {
		if (item[i].getSilver() == wantedToRemove.getSilver()) {
			item.erase(item.begin() + i);
			break;
		}
	}
}
template<>
inline void Backpack<Materials>::remove(Materials wantedToRemove) {
	if (slots == 0) {
		cout << "It is empty" << endl;
		return;
	}

	for (int i = 0; i < slots; i++) {
		if (item[i] == wantedToRemove) {
			item.erase(item.begin() + i);
			slots -= wantedToRemove.getSlots();
			break;
		}
	}

}

