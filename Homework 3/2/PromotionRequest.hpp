#pragma once
#include "Request.hpp"
class PromotionRequest : public Request
{
private:
	double amount;

public:
	PromotionRequest();
	PromotionRequest(const string& sender, double amount);
	double getAmount() const;
};

