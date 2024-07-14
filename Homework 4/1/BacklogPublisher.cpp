#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Averager* averager)
{
	Publishers::subscribe(averager);
	for (size_t i = 0; i < previousMessages.size(); i++) {
		averager->signal(previousMessages[i]);
	}
}

void BacklogPublisher::subscribe(MovingAverager* movingAverager)
{
	Publishers::subscribe(movingAverager);
	for (size_t i = 0; i < previousMessages.size(); i++) {
		movingAverager->signal(previousMessages[i]);
	}
}

void BacklogPublisher::subscribe(PeriodicSampler* periodicSampler)
{
	Publishers::subscribe(periodicSampler);
	for (size_t i = 0; i < previousMessages.size(); i++) {
		periodicSampler->signal(previousMessages[i]);
	}
}

void BacklogPublisher::unsubscribe(Averager* averager)
{
	Publishers::unsubscribe(averager);
}

void BacklogPublisher::unsubscribe(MovingAverager* movingAverager)
{
	Publishers::unsubscribe(movingAverager);
}

void BacklogPublisher::unsubscribe(PeriodicSampler* periodicSampler)
{
	Publishers::unsubscribe(periodicSampler);
}

void BacklogPublisher::signal(const Message& message)
{
	previousMessages.push_back(message);
	for (size_t i = 0; i < subscribers.size(); i++) {
		subscribers[i]->signal(message);
	}
}
