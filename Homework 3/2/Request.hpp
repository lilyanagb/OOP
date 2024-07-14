#pragma once
#include <string>
using namespace std;

class Request
{
private:
	string message;
	string sender;
	int ID;

public:
	static unsigned int counter;

	Request();
	Request(const string& message, const string& sender);
	string getMessage() const;
	string getSender() const;
	int getCount() const;
	int getID() const;
};

