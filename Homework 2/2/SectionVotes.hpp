#pragma once
#include <iostream>
enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};


class SectionVotes
{
private:
    int votes1;
    int votes2;
    int votes3;

public:
    SectionVotes();
    int getVotes1() const;
    int getVotes2() const;
    int getVotes3() const;

    SectionVotes(int party1Votes, int party2Votes, int party3Votes);

    int votesForParty(Party) const;

    friend std::istream& operator>>(std::istream& in, SectionVotes& votes);
    friend std::ostream& operator<<(std::ostream& out, const SectionVotes& votes);
};

