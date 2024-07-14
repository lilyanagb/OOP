#pragma once
#include "LimitedTwowayCounter.hpp"

class Semaphore : public LimitedTwowayCounter
{
	Semaphore();
	Semaphore(bool);
	bool isAvailable();
	void wait();
	void signal();
};