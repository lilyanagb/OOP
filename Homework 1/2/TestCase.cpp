#include "TestCase.hpp"

TestCase::TestCase(const std::string& name, const Error& error)
{
    this->name == name;
    this->error = error;
}

std::string TestCase::getName() const
{
    return this->name;
}

bool TestCase::isPassing() const
{
    if (error.getType() == ErrorType::None || error.getType() == ErrorType::Warning)
    {
        return true;
    }
    return false;
}

bool TestCase::hasError() const
{
    if (error.getType() != ErrorType::None) {
        return true;
    }
    return false;
}

ErrorType TestCase::getErrorType() const
{
    return error.getType();
}

std::string TestCase::getErrorMessage() const
{
    if (error.hasMessage()) {
        return error.getMessage();
   }
    return "";
}
