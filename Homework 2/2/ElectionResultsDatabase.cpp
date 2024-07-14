#include "ElectionResultsDatabase.hpp"
#include <iostream>
#include <fstream>
#include <string>

void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
	std::ifstream inputFile(filename);

	if (!inputFile.is_open()) {
		return;
	}
	
	while (inputFile >> sectionVotes) {
		votes.push_back(sectionVotes);
	};

	inputFile.close();
}

int ElectionResultsDatabase::numberOfSections() const
{
	return votes.size();
}

int ElectionResultsDatabase::votesForParty(Party party) const
{
	int allVotes1 = 0;
	int allVotes2 = 0;
	int allVotes3 = 0;
	for (int i = 0; i < votes.size(); i++) {
			allVotes1+= votes[i].getVotes1();
			allVotes2 += votes[i].getVotes2();
			allVotes3 += votes[i].getVotes3();
	}
	if (party == Party::PARTY1) {
		return allVotes1;
	}
	else if (party == Party::PARTY2) {
		return allVotes2;
	}
	else if (party == Party::PARTY3) {
		return allVotes3;
	}
}

Party ElectionResultsDatabase::winningParty() const
{
	int party1 = votesForParty(Party::PARTY1);
	int party2 = votesForParty(Party::PARTY2);
	int party3 = votesForParty(Party::PARTY3);

	if (party1 >= party2 && party1 >= party3) {
		return Party::PARTY1;
	}
	else if (party2 >= party1 && party2 >= party3) {
		return Party::PARTY2;
	}
	return Party::PARTY3;
}

std::istream& operator>>(std::istream& in, ElectionResultsDatabase& results)
{
	while (in >> results.sectionVotes) {
		results.votes.push_back(results.sectionVotes);
	}
	return in;
	
}

std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& results){
	for (int i = 0; i < results.votes.size() ; i++) {
		out << results.votes[i];
	}
	return out;
}
