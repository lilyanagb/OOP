#pragma once
#include "Message.hpp"
#include <string>
#include <vector>
using namespace std;

class Subscribers
{
public:
	Subscribers(const string& id = "");
	virtual ~Subscribers()=default;

	string getID() const;
	virtual void signal(const Message&)=0;
	virtual int read() const=0;

	virtual Subscribers* copy() const = 0;

protected:
	vector<Message> messages;

private:
	string id;
};

