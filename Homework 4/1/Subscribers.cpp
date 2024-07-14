#include "Subscribers.hpp"

Subscribers::Subscribers(const string& id) : id(id)
{
}

string Subscribers::getID() const
{
    return id;
}


