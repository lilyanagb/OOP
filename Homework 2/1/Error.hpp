#pragma once
#include <string>

class Error {
private:
    std::string myMessage;
public:
    void setError(const std::string&);
    Error(const std::string& message = "");
    std::string get_message() const;
};

