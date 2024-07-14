#pragma once
#include "Publishers.hpp"

class Repository 
{
public:
	Repository() = default;
	Repository(const Repository&);
	Repository& operator=(const Repository&);
	~Repository();

	void add(Averager*);
	void add(MovingAverager*);
	void add(PeriodicSampler*);

	Subscribers* get(const std::string& id);
private:
	vector<Subscribers*> subs;
};