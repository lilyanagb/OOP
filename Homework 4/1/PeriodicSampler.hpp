#pragma once
#include "Subscribers.hpp"

class PeriodicSampler : public Subscribers
{
public:
	PeriodicSampler(const string& id= "", size_t period= 0);
	size_t getPeriod() const;

	void signal(const Message&) override;
	int read() const override;

	Subscribers* copy() const override;
private:
	size_t period;
};
