#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter() : Counter(), LimitedCounter(), TwowayCounter()
{
	minValue = 0;
	maxValue = 0;
}

LimitedTwowayCounter::LimitedTwowayCounter(const int& min, const int& max)
	: Counter(), LimitedCounter(max), TwowayCounter(), minValue(min), maxValue(max)
{
}

LimitedTwowayCounter::LimitedTwowayCounter(const int& min, const int& max, const int& initial)
	: Counter(initial), LimitedCounter(max, initial), TwowayCounter(initial) ,minValue(min), maxValue(max)
{
}

LimitedTwowayCounter::LimitedTwowayCounter(const int& min, const int& max, const int& initial, const unsigned& step)
	: Counter(initial, step), LimitedCounter(max, initial, step), TwowayCounter(initial,step),  minValue(min), maxValue(max)
{
}

void LimitedTwowayCounter::increment()
{
	LimitedCounter::increment();
}

void LimitedTwowayCounter::decrement()
{
	int value = getTotal();
	unsigned int step = getStep();
	value -= step;

	if (value >= minValue) {
		TwowayCounter:: decrement();
	}
}

int LimitedTwowayCounter::getMin() const
{
	return minValue;
}

int LimitedTwowayCounter::getMax() const
{
	return LimitedCounter::getMax();
}

int LimitedTwowayCounter::getTotal() const
{
	return Counter::getTotal();
}

unsigned LimitedTwowayCounter::getStep() const
{
	return Counter::getStep();
}
