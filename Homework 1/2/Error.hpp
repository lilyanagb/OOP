#pragma once
#include <iostream>

enum class ErrorType {
    None,
    BuildFailed,
    Warning,
    FailedAssertion,
};

class Error {
public:
    Error();
    Error(const Error&);
    Error& operator=(const Error&);
    Error(ErrorType, const char*);

    bool hasMessage() const;
    const char* getMessage() const;
    ErrorType getType() const;
    static Error newNone();
    static Error newBuildFailed(const char* message);
    static Error newWarning(const char* message);
    static Error newFailedAssertion(const char* message);
    ~Error();
private:
    ErrorType type;
    char* optionalMessage;
    void setArr(const char*);

};

