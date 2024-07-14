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

Duelist::Duelist(string newName)
{
	name = newName;
}

Deck& Duelist::getDeck()
{
	return deck;
}

bool Duelist::saveDeck(const char* filename)
{
	static const char* const FILENAME_DECK = "_deck.txt";
	ofstream out;
	out.open(FILENAME_DECK, fstream::app);
	if (!out) {
		cout << "Error in opening the output file" << endl;
		return false;
	}

	out << deck.getDeckname() << "|" << deck.returnMonsterCards() << "|" << deck.returnMagicCards() << "|" << deck.returnPendulumCards() << "\n";

	for (const auto& monster : deck.getMonsterVector()) {
		out << monster.getName() << "|" << monster.getEffect() << "|"
			<< monster.getAttackingPoints() << "|" << monster.getProtectivePoints() << "\n";
	}

	for (const auto& magic : deck.getMagicVector()) {
		out << magic.getName() << "|" << magic.getEffect() << "|";

		if (magic.getCardType() == CardType::BUFF) {
			out << "BUFF" << "\n";
		}
		else if (magic.getCardType() == CardType::SPELL) {
			out << "SPELL" << "\n";
		}
		else if (magic.getCardType() == CardType::TRAP) {
			out << "TRAP" << "\n";
		}
	}

	for (const auto& pendulum : deck.getPendulumVector()) {
		out << pendulum.getName() << "|" << pendulum.getEffect() << "|"
			<< pendulum.getAttackingPoints() << "|" << pendulum.getProtectivePoints()
			<< "|" << pendulum.getPendulumScale() << "|";

		if (pendulum.getCardType() == CardType::BUFF) {
			out << "BUFF" << "\n";
		}
		else if (pendulum.getCardType() == CardType::SPELL) {
			out << "SPELL" << "\n";
		}
		else if (pendulum.getCardType() == CardType::TRAP) {
			out << "TRAP" << "\n";
		}
	}
	return true;
}

bool Duelist::loadDeck(const char* filename)
{
	deck.removeCardsFromDeck();

	ifstream in;
	in.open("_deck.txt");
	if (!in) {
		cout << "Error in opening the file" << endl;
		return false;
	}
	string myLine;

	while (getline(in, myLine)) {
		vector<string> line = split(myLine, "|");
		int trashCount = line.size() - 1;  //count of '|'

		string nameV, effectV;
		unsigned int attackingV = 0, protectiveV = 0, scaleV = 0;
		CardType typeV;

		if (trashCount == 3) {
			nameV = line[0];

			string look = "Deck";                               //if I have added a deck to the text file once 								
			string::size_type pos = nameV.find(look);			//and I want from main to add more cards I will have the name of Deck in the middle,
			if (pos != std::string::npos)						//which corresponds to trashcount=3 and will be considered as a monsterCard
			{
				continue;
			}

			effectV = line[1];
			attackingV = stoi(line[2]);
			protectiveV = stoi(line[3]);

			MonsterCard monster(nameV, effectV, attackingV, protectiveV);
			deck.addMonsterCard(monster);
		}
		else if (trashCount == 2) {
			nameV = line[0];
			effectV = line[1];
			typeV = convert(line[2]);

			MagicCard magic(nameV, effectV, typeV);
			deck.addMagicCard(magic);
		}
		else if (trashCount == 5) {
			nameV = line[0];
			effectV = line[1];
			attackingV = stoi(line[2]);
			protectiveV = stoi(line[3]);
			scaleV = stoi(line[4]);
			typeV = convert(line[5]);

			PendulumCard pendulum(nameV, effectV, attackingV, protectiveV, scaleV, typeV);
			deck.addPendulumCard(pendulum);
		}
	}
	return true;
}

CardType Duelist::convert(string& str)
{
	if (str == "TRAP") return CardType::TRAP;
	else if (str == "SPELL") return CardType::SPELL;
	else if (str == "BUFF") return CardType::BUFF;
}

vector<string> Duelist::split(const string& str, const string& delim)
{
	vector<string> tokens;
	size_t prev = 0, pos = 0;

	do {
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = str.length();
		string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());

	return tokens;
}
