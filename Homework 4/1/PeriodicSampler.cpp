#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(const string& id, size_t period)
	: Subscribers(id), period(period)
{
}

size_t PeriodicSampler::getPeriod() const
{
	return period;
}

void PeriodicSampler::signal(const Message& message)
{
	messages.push_back(message);
}

int PeriodicSampler::read() const
{
	if (messages.empty()) {
		return 0;
	}
	int lastNotIgnored = 0;
	for (size_t i = 0; i < messages.size(); i++) {
		if (i % period == 0) {
			lastNotIgnored = messages[i].getData();
		}
	}
	return lastNotIgnored;
}

Subscribers* PeriodicSampler::copy() const
{
	return new PeriodicSampler(*this);
}
