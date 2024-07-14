#include "SectionVotes.hpp"

SectionVotes::SectionVotes()
{
    votes1 = 0;
    votes2 = 0;
    votes3 = 0;
}

int SectionVotes::getVotes1() const
{
    return votes1;
}

int SectionVotes::getVotes2() const
{
    return votes2;
}

int SectionVotes::getVotes3() const
{
    return votes3;
}

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes)
{
    votes1 = party1Votes;
    votes2 = party2Votes;
    votes3 = party3Votes;
}

int SectionVotes::votesForParty(Party party) const
{
    if (party == 0) {
        return votes1;
    }
    if (party == 1) {
        return votes2;
    }
    if (party == 2) {
        return votes3;
    }
}

std::istream& operator>>(std::istream& in, SectionVotes& votes)
{
    in >> votes.votes1 >> votes.votes2 >> votes.votes3;
    votes = SectionVotes(votes.votes1,votes.votes2,votes.votes3);

    return in;
}

std::ostream& operator<<(std::ostream& out, const SectionVotes& votes)
{
    out << votes.votes1 << " " << votes.votes2 << " " << votes.votes3<<"\n";
    return out;
}

