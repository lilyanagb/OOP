#include "TeamLead.hpp"

TeamLead::TeamLead(const string& name, double salary)
{
	setName(name);
	setInitialSalary(salary);
	setTeamLead(this);
}

vector<Developer*> TeamLead::getTeam() const
{
	return developerObjects;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	if (developer != nullptr) {
		developer->setInitialSalary(salary);
		(*developer).setTeamLead(this);
		developerObjects.push_back(developer);
	}
}

void TeamLead::removeDeveloperFromTeam(const string& name)
{
	for (int i = developerObjects.size() - 1; i >= 0; --i) {
		if (developerObjects[i]->getName() == name) {
			developerObjects[i]->setTeamLead(nullptr);
			developerObjects.erase(developerObjects.begin() + i);
			return;
		}
	}
}

void TeamLead::increaseTeamSalariesBy(double amount)
{
	double a = 0;
	for (size_t i = 0; i < developerObjects.size(); i++) {
		a = developerObjects[i]->getSalary() + amount;
		developerObjects[i]->setSalary(a);
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
	double a = 0;
	for (size_t i = 0; i < developerObjects.size(); i++) {
		a = developerObjects[i]->getSalary() - amount;
		developerObjects[i]->setSalary(a);
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	leavingR.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	promotionR.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests()
{
	for (size_t i = 0; i < leavingR.size(); i++) {
		for (size_t j = 0; j < developerObjects.size(); j++) {
			if (leavingR[i].getSender() == developerObjects[j]->getName()) {
				developerObjects[j]->setTeamLead(nullptr);
				developerObjects.erase(developerObjects.begin() + j);
				break;
			}
		}
	}
	leavingR.clear();
}

void TeamLead::fulfillPromotionRequests()
{
	for (size_t i = 0; i < promotionR.size(); i++) {
		for (size_t j = 0; j < developerObjects.size(); j++) {
			if (promotionR[i].getSender() == developerObjects[j]->getName()) {
				developerObjects[i]->setSalary(promotionR[i].getAmount()+developerObjects[j]->getSalary());
				break;
			}
		}
	}
	promotionR.clear();
}
