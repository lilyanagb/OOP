#pragma once

#include <string>
using namespace std;

#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"

class TeamLead;
class Developer
{
private:
	TeamLead* lead;
	string name;
	double salary;

public:
	Developer();
	Developer(const string& name);

	string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead() const;

	void setInitialSalary(double amount);
	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
	void setTeamLead(TeamLead* leader);

	void setSalary(double amount);
	void setName(const string&);
};

