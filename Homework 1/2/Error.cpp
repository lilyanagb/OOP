#include "Error.hpp"

bool Error::hasMessage() const
{
    if (optionalMessage != nullptr) {
        return true;
    }
    return false;
}

const char* Error::getMessage() const
{
    return optionalMessage;
}

ErrorType Error::getType() const
{
    return type;
}

Error Error::newNone()
{
    return Error();
}

Error Error::newBuildFailed(const char* message)
{
    return Error(ErrorType::BuildFailed,message);
}

Error Error::newWarning(const char* message)
{
    return Error(ErrorType::Warning,message);
}

Error Error::newFailedAssertion(const char* message)
{
    return Error(ErrorType::FailedAssertion,message);
}

Error::Error(ErrorType error, const char* message)
{
    this->type = error;
    setArr(message);
}

void Error::setArr(const char* arr)
{
    if (arr != nullptr) {
 
        int i = 0;

        for (; arr[i] != '\0'; i++) {}


        this->optionalMessage = new char[i + 1];

        int j = 0;
        for (; arr[j] != '\0'; j++) {
            this->optionalMessage[j] = arr[j];
        }
        this->optionalMessage[i] = '\0';
    }
}


Error::Error() : optionalMessage(nullptr), type(ErrorType::None) {};

Error::Error(const Error& copyFrom)
{
        this->type = copyFrom.type;
        if (copyFrom.getMessage() == nullptr) {
            optionalMessage=nullptr;
        }
        else {
            setArr(copyFrom.getMessage());
        }
}

Error& Error::operator=(const Error& rhs)
{
    if (this != &rhs) {
       if (optionalMessage != nullptr) {
            delete[] optionalMessage;
        }
        setArr(rhs.getMessage());
        this->type = rhs.type;
    }
    return *this;
}
Error::~Error()
{
    delete[] optionalMessage;
}
