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

#include <iostream>
#include "Duelist.hpp"

int main() {
	Duelist firstDuelist("Ivan Ivanov");
	firstDuelist.loadDeck("magician_deck.txt"); //2 1 1 

	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 2500, 2100);
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", CardType::SPELL);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.",CardType::TRAP);
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 1200, 600, 8, CardType::SPELL); 
	
	firstDuelist.getDeck().setDeckname("Magician Deck");
	firstDuelist.getDeck().addMonsterCard(dragon);
	firstDuelist.getDeck().addMagicCard(swords);
	firstDuelist.getDeck().addMonsterCard(magician);
	firstDuelist.getDeck().addMagicCard(cylinder);
	firstDuelist.getDeck().addPendulumCard(timegazer);

	firstDuelist.saveDeck("magician_deck.txt"); //4 3 2 
	
	MagicCard box("Mystic Box", "Destroy one monster.", CardType::SPELL);
	firstDuelist.getDeck().changeMagicToDeck(1, box);

	firstDuelist.loadDeck("magician_deck.txt");  //6 4 3 
	return 0;
}