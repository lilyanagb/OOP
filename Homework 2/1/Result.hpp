#pragma once

#include "Error.hpp"
#include "Optional.hpp"

template<typename T>

class Result {
private:
    T result;
    Error error;
   
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    Optional<T> get_result() const;
    Optional<Error> get_error() const;

	bool operator==(const T&);
    bool operator==(const Error&);
};


template<typename T>
inline Result<T>::Result()
{
    result = T();
    error = Error();

}

template<typename T>
inline Result<T>::Result(const T& _result)
{
    result = _result;
}

template<typename T>
inline Result<T>::Result(const std::string& error_message)
{
    error.setError(error_message);
}


template<typename T>
inline Optional<T> Result<T>::get_result() const
{
    return result;
}

template<typename T>
inline Optional<Error> Result<T>::get_error() const
{
    return error;
}

template<typename T>
inline bool Result<T>::operator==(const T& newResult)
{
    if (error.get_message()== "") {
        return true;
    }
    return false;
}

template<typename T>
bool Result<T>::operator==(const Error& newResult)
{
    if (error.get_message() != "") {
        return true;
    }
    return false;
}

