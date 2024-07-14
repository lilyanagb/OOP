#pragma once
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"

class Publishers 
{
public:
	Publishers() = default;
	virtual ~Publishers() = default;

	virtual void subscribe(Averager*);
	virtual void subscribe(MovingAverager*);
	virtual void subscribe(PeriodicSampler*);

	virtual void unsubscribe(Averager*);
	virtual void unsubscribe(MovingAverager*);
	virtual void unsubscribe(PeriodicSampler*);

	virtual void signal(const Message&)=0;
protected:
	vector<Subscribers*> subscribers;
};

