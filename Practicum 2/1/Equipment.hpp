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
#include "Armor.hpp"
#include "Weapon.hpp"

template<typename T>
class Equipment
{
private:
	int slots;
	vector<T> itemList;

public:
	Equipment();

	int getSlots() const;

	bool isEmpty();
	bool isFull();
	void clear();
	void add(T);
	void remove(T);
	T returnTheBest();

	bool operator==(const Equipment<T>&);
	bool operator!=(const Equipment<T>&);
	double calculate();

	void print();

};

template<typename T>
inline bool Equipment<T>::operator==(const Equipment<T>& rhs)
{
	return this->calculate() == rhs.calculate();
}

template<typename T>
inline bool Equipment<T>::operator!=(const Equipment<T>& rhs)
{
	return this->calculate() != rhs.calculate();
}

template<class T>
inline Equipment<T>::Equipment()
{
	slots = 0;
}

template<typename T>
inline int Equipment<T>::getSlots() const
{
	return slots;
}

template<class T>
inline bool Equipment<T>::isEmpty()
{
	if (slots == 0) {
		return true;
	}
	return false;
}

template<class T>
inline bool Equipment<T>::isFull()
{
	if (slots >= 24) {
		return true;
	}
	return false;
}

template<class T>
inline void Equipment<T>::clear()
{
	itemList.clear();
	slots = 0;
}

template<class T>
inline void Equipment<T>::add(T newItem)
{
	if (slots >= 24) {
		cout << "It is full" << endl;
		return;
	}

	itemList.push_back(newItem);
	slots += newItem.getSlots();
}

template<class T>
inline void Equipment<T>::remove(T wantedToRemove)
{
	return;
}

template<typename T>
inline double Equipment<T>::calculate()
{
	return false;
}

template<typename T>
inline void Equipment<T>::print()
{
	int size = itemList.size();
	for(int i=0;i<size;i++)
		itemList[i].print();

}

template<>
inline double Equipment<Weapon>::calculate()
{
	int size = itemList.size();
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += itemList[i].getWeaponScore();
	}
	return sum;
}
template<>
inline double Equipment<Armor>::calculate()
{
	double sum = 0;
	int size = itemList.size();
	for (int i = 0; i < size; i++) {
		sum += itemList[i].getGearscore();
	}
	return sum;
}
template<>
inline void Equipment<Weapon>::remove(Weapon wantedToRemove)
{

	for (int i = 0; i < slots; i++) {
		if (itemList[i].getWeaponKind() == wantedToRemove.getWeaponKind()) {
			itemList.erase(itemList.begin() + i);
			slots -= wantedToRemove.getSlots();
			break;
		}
	}
}
template<>
inline void Equipment<Armor>::remove(Armor wantedToRemove)
{
	if (slots == 0) {
		cout << "It is empty" << endl;
		return;
	}

	for (int i = 0; i < slots; i++) {
		if (itemList[i].getType() == wantedToRemove.getType()) {
			itemList.erase(itemList.begin() + i);
			slots -= wantedToRemove.getSlots();
			break;
		}
	}
}

template<class T>
inline T Equipment<T>::returnTheBest()
{
	return T();
}


template<>
inline Weapon Equipment<Weapon>::returnTheBest() {

	int i = 0;
	int indexOfBest = 0;
	double bestResult = itemList[i].getWeaponScore();
	for (; i < slots; i++) {
		if (bestResult < itemList[i].getWeaponScore()) {
			bestResult = itemList[i].getWeaponScore();
			indexOfBest = i;
		}
	}
	return itemList[indexOfBest];
}
template<>
inline Armor Equipment<Armor>::returnTheBest() {

	int i = 0;
	int indexOfBest = 0;
	double bestResult = itemList[i].getGearscore();
	for (; i < slots; i++) {
		if (bestResult < itemList[i].getGearscore()) {
			bestResult = itemList[i].getGearscore();
			indexOfBest = i;
		}
	}
	return itemList[indexOfBest];
}