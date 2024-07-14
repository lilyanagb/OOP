#include "MovingAverager.hpp"

MovingAverager::MovingAverager(const string& id, size_t windowSize)
    :Subscribers(id), windowSize(windowSize)
{
    countOfDatas = 0;
}

size_t MovingAverager::getWindowSize() const
{
    return windowSize;
}

void MovingAverager::signal(const Message& message)
{
    messages.push_back(message.getData());
}

int MovingAverager::read() const
{
    if (messages.empty() || windowSize==0) {
        return 0;
    }
    int sum = 0;
    size_t count = 0; 
    
    if (windowSize > count && windowSize < messages.size()) {
        for (size_t i = messages.size() - windowSize; i < messages.size(); i++) {
            sum += messages[i].getData();
            count++;
        }
    }
    else if (windowSize >= messages.size())
    {
        for (size_t i = 0; i < messages.size(); i++) {
            sum += messages[i].getData();
            count++;
        }
    }
    return sum / count;
}

Subscribers* MovingAverager::copy() const
{
    return new MovingAverager(*this);
}
