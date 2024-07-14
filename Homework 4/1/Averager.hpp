#pragma once
#include "Subscribers.hpp"

class Averager :public Subscribers 
{
public:
	Averager(const string& id= "");
	
	int read() const override;
	void signal(const Message&) override;

	Subscribers* copy() const override;
};