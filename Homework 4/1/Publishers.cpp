#include "Publishers.hpp"

void Publishers::subscribe(Averager* averager)
{
	subscribers.push_back(averager);
}

void Publishers::subscribe(MovingAverager* movingAverager)
{
	subscribers.push_back(movingAverager);

}

void Publishers::subscribe(PeriodicSampler* periodicSampler)
{
	subscribers.push_back(periodicSampler);
}

void Publishers::unsubscribe(Averager* averager)
{
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscribers[i]->getID() == averager->getID()) {
			subscribers.erase(subscribers.begin() + i);
			return;
		}
	}
}

void Publishers::unsubscribe(MovingAverager* movingAverager)
{
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscribers[i]->getID() == movingAverager->getID()) {
			subscribers.erase(subscribers.begin() + i);
			return;
		}
	}
}

void Publishers::unsubscribe(PeriodicSampler* periodicSampler)
{
	for (size_t i = 0; i < subscribers.size(); i++) {
		if (subscribers[i]->getID() == periodicSampler->getID()) {
			subscribers.erase(subscribers.begin() + i);
			return;
		}
	}
}
