#pragma once
#include <string>
using namespace std;

class Debug
{
public:
    virtual ~Debug() = default;

    virtual string debug_print() const=0;
};

