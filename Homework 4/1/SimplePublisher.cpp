#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Averager* averager)
{
	Publishers::subscribe(averager);
}

void SimplePublisher::subscribe(MovingAverager* movingAverager)
{
	Publishers::subscribe(movingAverager);
}

void SimplePublisher::subscribe(PeriodicSampler* periodicSampler)
{
	Publishers::subscribe(periodicSampler);
}

void SimplePublisher::unsubscribe(Averager* averager)
{
	Publishers::unsubscribe(averager);
}

void SimplePublisher::unsubscribe(MovingAverager* movingAverager)
{
	Publishers::unsubscribe(movingAverager);
}

void SimplePublisher::unsubscribe(PeriodicSampler* periodicSampler)
{
	Publishers::unsubscribe(periodicSampler);
}

void SimplePublisher::signal(const Message& message) 
{
	for (size_t i = 0; i < subscribers.size(); i++) {
		subscribers[i]->signal(message);
	}
}
