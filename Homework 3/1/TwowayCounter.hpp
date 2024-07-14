#pragma once
#include "Counter.hpp"

class TwowayCounter : virtual public Counter
{
public:
	TwowayCounter()=default;
	TwowayCounter(const int& initial);
	TwowayCounter(const int& initial, const unsigned& step);

	void decrement();
};

