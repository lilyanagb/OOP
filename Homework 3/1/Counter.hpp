#pragma once
class Counter
{
private:
	int initialValue;
	unsigned counterStep;
	int currentValue;

public:
	Counter();
	Counter(const int& initial);
	Counter(const int& initial, const unsigned& step);

	void increment();

	int getTotal() const;
	unsigned getStep() const;

	void setCurrentValue(const int&);
	void setInitialValue(const int&);
	void setCounterStep(const unsigned&);
};

