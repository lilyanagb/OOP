#include "Repository.hpp"

Repository::Repository(const Repository& copyFrom)
{
	for (auto x : copyFrom.subs) {
		subs.push_back(x->copy());
	}
}

Repository& Repository::operator=(const Repository& rhs)
{
	if (this != &rhs) {
		subs.clear();
		for (auto x : rhs.subs) {
			subs.push_back(x->copy());
		}
	}
	return *this;
}

Repository::~Repository()
{
	subs.clear();
}

void Repository::add(Averager* averager)
{
	subs.push_back(averager->copy());
}

void Repository::add(MovingAverager* movingAverager)
{
	subs.push_back(movingAverager->copy());
}

void Repository::add(PeriodicSampler* periodicSampler)
{
	subs.push_back(periodicSampler->copy());
}

Subscribers* Repository::get(const std::string& id)
{
	for (size_t i = 0; i < subs.size(); i++) {
		if (subs[i]->getID() == id) {
			return subs[i];
		}
	}
	return nullptr;
}
