#include "KeyValueDatabase.hpp"

KeyValueDatabase::KeyValueDatabase(const string& name, const string& location, const string& extension)
    : Object(name,location,extension)
{
}

void KeyValueDatabase::add_entry(const pair<string, int>& entry) 
{
    for (size_t i = 0; i < keys.size(); i++) {
        if (keys[i].first == entry.first) {
           throw invalid_argument ("The key is already contained");
        }
    }

    keys.push_back(entry);
}

int KeyValueDatabase::get_value(const string& key) const
{
    for (size_t i = 0; i < keys.size(); i++) {
        if (key == keys[i].first) {
            return keys[i].second;
        }
    }
    throw invalid_argument("The key is invalid");
}

string KeyValueDatabase::debug_print() const
{
    stringstream sw;
    string stringword;
    int pos = 0;
    for (size_t i = 0; i < keys.size(); i++)
    {
        pos++;
        sw << "{"<<keys[i].first << ":" << keys[i].second <<"}"<< endl;
    }
   
    stringword = sw.str();
    return stringword;
}

bool KeyValueDatabase::operator==(const Comparable* comp) const
{
        Comparable* compV = const_cast<Comparable*>(comp);
        KeyValueDatabase* keyValue = dynamic_cast<KeyValueDatabase*>(compV);
        if (keyValue) {
            if (keys.size() != keyValue->keys.size()) {
                return false;
            }
            for (size_t i = 0; i < keys.size(); i++) {
                if ((keys[i].first != keyValue->keys[i].first) || (keys[i].second != keyValue->keys[i].second)) {
                    return false;
                }
           }
            return true;
        }
    return false;
}

bool KeyValueDatabase::operator!=(const Comparable* comp) const
{
        Comparable* compV = const_cast<Comparable*>(comp);
        KeyValueDatabase* keyValue = dynamic_cast<KeyValueDatabase*>(compV);
        if (keyValue) {
            if (keys.size() != keyValue->keys.size()) {
                return true;
            }
            for (size_t i = 0; i < keys.size(); i++) {
                if (keys[i] != keyValue->keys[i]) {
                    return true;
                }
            }
            return false;
        }
    return true;
}
 
string KeyValueDatabase::to_string() const
{
    string myLine;
    string forName = get_name();
    string forLocation = get_location();
    string forExtension = get_extension();

    stringstream sw;
    string stringword;
 
    sw << forName << endl << forLocation << endl << forExtension << endl;
    for (size_t i = 0; i < keys.size(); i++)
    {
        sw <<keys[i].first<<":"<<keys[i].second << endl;
    }
    stringword = sw.str();

    return stringword;
}

void KeyValueDatabase::from_string(const string& s)
{
    keys.clear();
    string temp = "";
    int count = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == '\n') {
            count++;
            if (count < 4 || temp == "") {
                if (count == 1) {
                    name = temp;
                }
                else if (count == 2) {
                    location = temp;
                }
                extension = temp;
                temp = "";
                continue;
            }
            vector<string> line = split(temp, ":");
            entry.first = line[0];
            entry.second = stoi(line[1]);
            keys.push_back(entry);
            temp = "";
        }
        else {
        temp.push_back(s[i]);
        }
}
    }


Object* KeyValueDatabase::clone() const
{
    return new KeyValueDatabase(*this);
}

vector<string> KeyValueDatabase::split(const string& str, const string& delim)
{
    vector<string> tokens;
    size_t prev = 0, pos = 0;

    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());

    return tokens;
}
