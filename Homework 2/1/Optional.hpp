#pragma once

template <typename T>

class Optional {
private:
    T element;
public:
    Optional();
    Optional(const T& value);

    Optional(const Optional&);
    Optional& operator=(const Optional&);

    bool is_none() const;
    T get_value() const;
};

template<typename T>
inline Optional<T>::Optional() 
{
    element = T();
}

template<typename T>
inline Optional<T>::Optional(const T& value) : element(value) { }

template<typename T>
inline Optional<T>::Optional(const Optional& copyFrom)
{
    element = copyFrom.element;
}

template<typename T>
inline Optional<T>& Optional<T>::operator=(const Optional& rhs)
{
    if (this != &rhs) {
        element = rhs.element;
    }
    return *this;
}

template<typename T>
inline bool Optional<T>::is_none() const
{
    if (element == T()) {
        return true;
    }
    return false;
}

template<typename T>
inline T Optional<T>::get_value() const
{
    return element;
}
