#include "Semaphore.hpp"

Semaphore::Semaphore() : LimitedTwowayCounter()
{
	setInitialValue(0);
}

Semaphore::Semaphore(bool isTrue)
{
	if (isTrue) {
		setInitialValue(1);
	}
	else {
		setInitialValue(0);
	}
}

bool Semaphore::isAvailable()
{
	if (getTotal() > 0) {
		return true;
	}
	return false;
}

void Semaphore::wait()
{
	LimitedTwowayCounter::decrement();
}

void Semaphore::signal()
{
	LimitedTwowayCounter::increment();
}
