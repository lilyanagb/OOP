#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer()
{
	name = "";
	salary = 0;
	lead = nullptr;
}

Developer::Developer(const string& name)
{
	this->name = name;
	salary = 0;
	lead = nullptr;
}

string Developer::getName() const
{
	return name;
}

double Developer::getSalary() const
{
	return salary;
}

TeamLead* Developer::getTeamLead() const
{
	return lead;
}

void Developer::setInitialSalary(double amount)
{
	if (salary == 0) {
		salary = amount;
	}
}

void Developer::sendLeavingRequest()
{
	if (lead != nullptr) {
		LeavingRequest request = LeavingRequest(name);
		lead->addLeavingRequest(request);
	}
}

void Developer::sendPromotionRequest(double amount)
{
	if (lead != nullptr) {
		PromotionRequest request = PromotionRequest(name, amount);
		lead->addPromotionRequest(request);
	}
}

void Developer::setTeamLead(TeamLead* leader)
{
	lead = leader;
}

void Developer::setSalary(double amount)
{
	salary = amount;
}

void Developer::setName(const string& newName)
{
	name = newName;
}
