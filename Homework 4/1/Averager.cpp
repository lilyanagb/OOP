#include "Averager.hpp"

Averager::Averager(const string& id) : Subscribers(id)
{
}

int Averager::read() const
{
    if (messages.empty()) {
        return 0;
    }

    int sum = 0;
    int count = 0;
    for (auto number : messages) {
        sum += number.getData();
        count++;
    }
    
    return sum / count;
}

void Averager::signal(const Message& message)
{
    messages.push_back(message);
}

Subscribers* Averager::copy() const
{
    return new Averager(*this);
}
