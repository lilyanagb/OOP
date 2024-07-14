#include "Error.hpp"

void Error::setError(const std::string& newMessage)
{
	myMessage = newMessage;
}

Error::Error(const std::string& message)
{
	myMessage = message;
}

std::string Error::get_message() const
{
	return myMessage;
}
