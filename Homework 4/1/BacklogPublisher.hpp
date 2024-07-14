#pragma once
#include "Publishers.hpp"

class BacklogPublisher : public Publishers
{
public:
	BacklogPublisher() = default;

	void subscribe(Averager*) override;
	void subscribe(MovingAverager*) override;
	void subscribe(PeriodicSampler*) override;

	void unsubscribe(Averager*) override;
	void unsubscribe(MovingAverager*) override;
	void unsubscribe(PeriodicSampler*) override;

	void signal(const Message&) override;
private:
	vector<Message> previousMessages;
};