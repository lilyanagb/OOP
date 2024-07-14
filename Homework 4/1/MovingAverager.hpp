#pragma once
#include "Subscribers.hpp"

class MovingAverager : public Subscribers
{
public:
	MovingAverager(const string& id= "", size_t windowSize=0);
	size_t getWindowSize() const;
	void signal(const Message&) override;
	int read() const override;

	Subscribers* copy() const override;
private:
	size_t countOfDatas;
	size_t windowSize;
};