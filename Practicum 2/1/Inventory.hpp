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
#include "Backpack.hpp"
#include "Equipment.hpp"

template <typename T>
class Inventory {
private:
	vector<T> obj;
	int slots;
public:
	Inventory();

	bool operator==(const Inventory<T>&);
	bool operator!=(const Inventory<T>&);
	friend ostream& operator<<(ostream& out, Inventory<T> items) {
		int size = items.obj.size();
		for (int i = 0; i < size; i++) {
			items.obj[i].print();
		}
		return out;
	}
	void add(T);
	void remove(T);
	int calculate();
};

template<typename T>
inline Inventory<T>::Inventory()
{
	slots = 0;
}

template<typename T>
inline bool Inventory<T>::operator==(const Inventory<T>& item)
{
	return this->calculate() == item.calculate();
}

template<typename T>
inline bool Inventory<T>::operator!=(const Inventory<T>& item)
{
	return !(this->calculate() == item.calculate());
}


template<typename T>
inline void Inventory<T>::add(T itemList)
{
	obj.push_back(itemList);
	slots += itemList.getSlots();
}

template<typename T>
inline void Inventory<T>::remove(T wantedToRemove)
{
	for (int i = 0; i < slots; i++) {
		if (obj[i] == wantedToRemove) {
			obj.erase(obj.begin() + i);
			break;
		}
	}
}

template<typename T>
inline int Inventory<T>::calculate()
{
	int size = obj.size();
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += obj[i].getSlots();
	}
	return sum;
}
