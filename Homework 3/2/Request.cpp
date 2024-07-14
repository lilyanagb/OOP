#include "Request.hpp"

unsigned int Request::counter = 0;

Request::Request()
{
    message = "";
    sender = "";
    counter++;
    ID = counter;
}

Request::Request(const string& message, const string& sender)
{
    this->message = message;
    this->sender = sender;
    counter++;
    ID = counter;
}

string Request::getMessage() const
{
    return message;
}

string Request::getSender() const
{
    return sender;
}

int Request::getCount() const
{
    return counter;
}

int Request::getID() const
{
    return ID;
}

