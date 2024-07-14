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

#include "Inventory.hpp"
#include <iostream>
using namespace std;

int main() {
	Inventory<Equipment<Armor>> armorTest;
	Equipment<Armor> armorItems;

	Armor firstArmor1;
	firstArmor1.addEffect("neshto1", 150);
	firstArmor1.addEffect("neshto2", 15.23);
	firstArmor1.addEffect("neshto3", 3000);
	Armor secondArmor2;
	secondArmor2.addEffect("nikoi", 20);
	secondArmor2.addEffect("nikoi1", 36);
	Armor thirdArmor3;
	thirdArmor3.addEffect("fire", 3.3);
	thirdArmor3.addEffect("water", 111);
	thirdArmor3.addEffect("fire", 7);
	thirdArmor3.addEffect("wind", 111);
	armorItems.add(firstArmor1);
	armorItems.add(secondArmor2);
	armorItems.add(thirdArmor3);

	cout << armorItems.getSlots() << endl;
	thirdArmor3.setDefense(3);

	armorTest.add(armorItems);
	//armorItems.print();
	cout << armorTest;
	cout << endl;

	Inventory<Equipment<Weapon>> weaponTest;
	Equipment<Weapon> weaponItems;
	Weapon firstWeapon1;
	firstWeapon1.addEffect("hehe1", 150);
	firstWeapon1.addEffect("hehe2", 15.23);
	firstWeapon1.addEffect("hehe3", 3000);
	Weapon secondWeapon2;
	secondWeapon2.addEffect("ooo1", 20);
	secondWeapon2.addEffect("ooo2", 36);
	Weapon thirdWeapon3;
	thirdWeapon3.addEffect("fire", 3.3);
	thirdWeapon3.addEffect("water", 111);
	thirdWeapon3.addEffect("fire", 7);
	thirdWeapon3.addEffect("wind", 111);
	weaponItems.add(firstWeapon1);
	weaponItems.add(secondWeapon2);
	weaponItems.add(thirdWeapon3);

	Equipment<Weapon> weaponItems1;
	Weapon firstWeapon4;
	firstWeapon4.addEffect("Lily1", 150);
	firstWeapon4.addEffect("Marielka1", 15.23);
	firstWeapon4.addEffect("Mimi1", 3000);
	Weapon secondWeapon5;
	secondWeapon5.addEffect("Nikoi", 20);
	secondWeapon5.addEffect("Nikoi1", 36);
	Weapon thirdWeapon6;
	thirdWeapon6.addEffect("fire", 3.3);
	thirdWeapon6.addEffect("water", 111);
	thirdWeapon6.addEffect("fire", 7);
	thirdWeapon6.addEffect("wind", 111);
	thirdWeapon6.changeWeaponKind("staff");
	weaponItems1.add(firstWeapon4);
	weaponItems1.add(secondWeapon5);
	weaponItems1.add(thirdWeapon6);

	weaponTest.add(weaponItems);
	//weaponItems1.print();
	cout << weaponTest;
	cout << endl;

	cout << weaponItems1.isEmpty() << endl;
	cout << weaponItems1.isFull() << endl;
	cout << endl;
	weaponItems1.remove(thirdWeapon3);
	cout << weaponItems1.getSlots() << endl;
	weaponItems1.clear();
	cout << weaponItems1.getSlots() << endl;
	cout << weaponItems1.isEmpty() << endl;
	cout << weaponItems1.isFull() << endl;
	cout << endl;

	Equipment<Weapon> weapon;
	Weapon Weapon4(HandleTypes::oneHanded, "l", 100, 200);
	Weapon Weapon5(HandleTypes::twoHanded, "m", 1, 2);
	Weapon Weapon6(HandleTypes::oneHanded, "n", 800, 1450);
	Weapon Weapon7(HandleTypes::twoHanded, "o", 5, 45);
	weapon.add(Weapon4);
	weapon.add(Weapon5);
	weapon.add(Weapon6);
	weapon.add(Weapon7);
	Weapon theBest = weapon.returnTheBest();
	cout << theBest.getWeaponScore() << endl;

	Armor best = armorItems.returnTheBest();
	cout << best.getGearscore() << endl;
	cout << endl;

	Inventory < Backpack<Money>> moneyTest;
	Backpack<Money> moneyItems;
	Money money1;
	money1.setSilverCount(101);
	money1.setSilverCount(99);
	money1.count();
	moneyItems.add(money1);
	Money money2;
	money2.setSilverCount(260);
	money2.count();
	moneyItems.add(money2);

	cout << moneyItems.getSlots() << endl;
	moneyTest.add(moneyItems);
	//moneyItems.print();
	cout << moneyTest;
	cout << endl;

	Inventory<Backpack<Materials>> materialsTest;
	Backpack<Materials> materialItems;
	Materials material1;
	material1.addMaterial(MaterialTypes::cloth, 36);
	material1.addMaterial(MaterialTypes::essence, 10);
	materialItems.add(material1);
	Materials again;
	again.addMaterial(MaterialTypes::herbs, 4);
	again.addMaterial(MaterialTypes::ores, 1);
	again.addMaterial(MaterialTypes::cloth, 2); 
	materialItems.add(again);
	cout << materialItems.getSlots() << endl;
	materialItems.remove(again); 
	cout << materialItems.getSlots() << endl;
	materialsTest.add(materialItems);
	//materialItems.print();
	cout << materialsTest;
	return 0;
}