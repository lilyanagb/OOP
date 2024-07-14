#include "Counter.hpp"

Counter::Counter()
{
    initialValue = 0;
    counterStep = 1;
    currentValue = 0;
}

Counter::Counter(const int& initial)
{
    initialValue = initial;
    counterStep = 1;
    currentValue = initialValue;
}

Counter::Counter(const int& initial, const unsigned& step)
{
    initialValue = initial;
    counterStep = step;
    currentValue = initialValue;
}

void Counter::increment()
{
    currentValue += counterStep;
}

int Counter::getTotal() const
{
    return currentValue;
}

unsigned Counter::getStep() const
{
    return counterStep;
}

void Counter::setCurrentValue(const int& newValue)
{
    currentValue = newValue;
}

void Counter::setInitialValue(const int& newValue)
{
    initialValue = newValue;
}

void Counter::setCounterStep(const unsigned& newStep)
{
    counterStep = newStep;
}
