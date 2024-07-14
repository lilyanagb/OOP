#pragma once
#include "Object.hpp"

class KeyValueDatabase : public Object
{
public:
    KeyValueDatabase(const string& name, const string& location, const string& extension);

    void add_entry(const pair<string, int>& entry);
    int get_value(const string& key) const;

    string debug_print() const override;
    bool operator==(const Comparable*) const override;
    bool operator!=(const Comparable*) const override;

    string to_string() const override;
    void from_string(const string&) override;

    Object* clone() const override;
private:
    vector<string> split(const string& str, const string& delim);

    pair<string, int> entry;
    vector<pair<string, int>> keys;
};

