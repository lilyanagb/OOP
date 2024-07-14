#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter() : Counter()
{
	maxValue = 0;
}

LimitedCounter::LimitedCounter(const int& max)
	: Counter(0,1), maxValue(max)
{
}

LimitedCounter::LimitedCounter(const int& max, const int& initial)
	: Counter(initial,1), maxValue(max)
{
}

LimitedCounter::LimitedCounter(const int& max, const int& initial, const unsigned& step)
	: Counter(initial, step), maxValue(max)
{
}

void LimitedCounter::increment()
{
	int value = getTotal();
	unsigned int step = getStep();
	value += step;

	if (value <= maxValue) {
		Counter::increment();
	}
}

int LimitedCounter::getMax() const
{
	return maxValue;
}

int LimitedCounter::getTotal() const
{
	return Counter::getTotal();
}

unsigned LimitedCounter::getStep() const
{
	return Counter::getStep();
}
