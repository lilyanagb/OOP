#include "TwowayCounter.hpp"

TwowayCounter::TwowayCounter(const int& initial) 
	: Counter(initial)
{
}

TwowayCounter::TwowayCounter(const int& initial, const unsigned& step)
	: Counter(initial, step)
{
}

void TwowayCounter::decrement()
{
	int value = getTotal();
	unsigned step = getStep();
	value -= step;

	setCurrentValue(value);
}
