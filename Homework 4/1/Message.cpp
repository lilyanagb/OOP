#include "Message.hpp"

Message::Message(const int data) : data(data) {}

int Message::getData() const
{
    return this->data;
}
