#pragma once
#include "SectionVotes.hpp"
#include <vector>

class ElectionResultsDatabase
{
private:
    std::vector<SectionVotes> votes;
    SectionVotes sectionVotes;

public:
    void addResultsFromFile(const char* filename);

    int numberOfSections() const;

    int votesForParty(Party) const;

    Party winningParty() const;

    friend std::istream& operator>>(std::istream& in, ElectionResultsDatabase& results);
    friend std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& results);
};
