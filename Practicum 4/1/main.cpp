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

#include "Duelist.hpp"

int main() {
	MonsterCard dragon("Blue-Eyes White Dragon", "This legendary dragon is a powerful engine of destruction.", 43, 3000, 2500);
	MonsterCard magician("Dark Magician", "The ultimate wizard.", 0, 2500, 2100);
	MagicCard swords("Swords of Revealing Light", "Your opponent's monsters cannot declare an attack.", 13, CardType::SPELL);
	MagicCard cylinder("Magic Cylinder", "Inflict damage to your opponent equal to its ATK.", 19,CardType::TRAP);
	PendulumCard timegazer("Timegazer Magician", "Your opponent cannot activate Trap Magic Cards", 14, 1200, 600, 8, CardType::SPELL);

	Duelist firstDuelist("Ivan Ivanov");
	firstDuelist.getDeck().setDeckname("Magician Deck");
	firstDuelist.getDeck().addCard(&dragon);
	firstDuelist.getDeck().addCard(&magician);
	firstDuelist.getDeck().addCard(&swords);
	firstDuelist.getDeck().addCard(&cylinder);
	firstDuelist.getDeck().addCard(&timegazer);

	firstDuelist.saveDeck("magician_deck.txt");

	MagicCard box("Mystic Box", "Destroy one monster.", 0, CardType::SPELL);
	firstDuelist.getDeck().changeCardInDeck(2, &box);

	firstDuelist.getDeck().shuffle();
	firstDuelist.saveDeck("magician_deck.txt");

	Duelist secondDuelist("Gosho Goshev");
	secondDuelist.getDeck().setDeckname("Monster Deck");
	secondDuelist.getDeck().addCard(&dragon);
	secondDuelist.getDeck().addCard(&magician);
	secondDuelist.getDeck().addCard(&swords);
	secondDuelist.getDeck().addCard(&cylinder);
	secondDuelist.getDeck().addCard(&timegazer);

	secondDuelist.saveDeck("magician_deck.txt");

	firstDuelist.duel(secondDuelist);

	firstDuelist.loadDeck("input.txt");
	firstDuelist.saveDeck("neshto.txt");
	firstDuelist.duel(secondDuelist);

	return 0;
}