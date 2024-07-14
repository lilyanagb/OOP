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

#include "Materials.hpp"
#include <iostream>
using namespace std;

int Materials::getSlots() const
{
	int slots = 0;

	slots += herbsCount / 20;
	slots += oresCount / 20;
	slots += clothCount / 20;
	slots += essenceCount / 10;

	if (herbsCount % 20 != 0) {
		slots++;
	}
	if (oresCount % 20 != 0) {
		slots++;
	}
	if (clothCount % 20 != 0) {
		slots++;
	}
	if (essenceCount % 10 != 0) {
		slots++;
	}

	return slots;
}

int Materials::getHerbs() const
{
	return herbsCount;
}

int Materials::getOres() const
{
	return oresCount;
}

int Materials::getCloth() const
{
	return clothCount;
}

int Materials::getEssence() const
{
	return essenceCount;
}

Materials::Materials()
{
	herbsCount = 0;
	oresCount = 0;
	clothCount = 0;
	essenceCount = 0;
}

Materials::Materials(int herbs, int ores, int cloth, int essence)
{
	this->herbsCount = herbs;
	this->oresCount = ores;
	this->clothCount = cloth;
	this->essenceCount = essence;
}

bool Materials::operator==(Materials newItem)
{
	if (herbsCount == newItem.herbsCount) {
		if (oresCount == newItem.oresCount) {
			if (essenceCount == newItem.essenceCount) {
				if (clothCount == newItem.clothCount) {
					return true;
				}
			}
		}
	}
	return false;
}

void Materials::addMaterial(MaterialTypes newType, int count)
{
	if (newType == MaterialTypes::essence) {
		essenceCount += count;
	}
	else if (newType == MaterialTypes::herbs) {
		herbsCount += count;
	}
	else if (newType == MaterialTypes::ores) {
		oresCount += count;
	}
	else if (newType == MaterialTypes::cloth) {
		clothCount += count;
	}
}

void Materials::print()
{
	cout << "Herbs: " << herbsCount << " Ores: " << oresCount << " Cloth: " << clothCount << " Essence: " << essenceCount << endl;
}
