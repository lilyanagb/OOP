#pragma once
#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"

class LimitedTwowayCounter : public LimitedCounter, public TwowayCounter
{
private:
	int minValue;
	int maxValue;

public:
	LimitedTwowayCounter();
	LimitedTwowayCounter(const int& min, const int& max);
	LimitedTwowayCounter(const int& min, const int& max, const int& initial);
	LimitedTwowayCounter(const int& min, const int& max, const int& initial, const unsigned& step);
	
	void increment();
	void decrement();

	int getMin() const;
	int getMax() const;
	int getTotal() const;
	unsigned getStep() const;
};

