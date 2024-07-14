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

enum class MaterialTypes {
	essence,
	herbs,
	ores,
	cloth
};

class Materials
{
private:
	int herbsCount;
	int oresCount;
	int clothCount;
	int essenceCount;

public:
	int getSlots() const;

	int getHerbs() const;
	int getOres() const;
	int getCloth() const;
	int getEssence() const;

	Materials();
	Materials(int, int, int, int);

	bool operator==(Materials);
	void addMaterial(MaterialTypes, int);

	void print();
};

