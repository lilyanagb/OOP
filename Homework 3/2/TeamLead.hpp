#pragma once
#include "Developer.hpp"
#include <vector>

class TeamLead : public Developer {
private:
	vector<Developer*> developerObjects;
	vector<LeavingRequest> leavingR;
	vector<PromotionRequest> promotionR;

public:
	TeamLead(const string& name, double salary);

	vector<Developer*> getTeam() const;

	void addDeveloperToTeam(Developer* developer, double salary);
	void removeDeveloperFromTeam(const string& name);
	void increaseTeamSalariesBy(double amount);
	void decreaseTeamSalariesBy(double amount);
	void addLeavingRequest(const LeavingRequest& leavingRequest);
	void addPromotionRequest(const PromotionRequest& promotionRequest);
	void fulfillLeavingRequests();
	void fulfillPromotionRequests();
};

