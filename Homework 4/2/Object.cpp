#include "Object.hpp"

Object::Object(const string& name, const string& location, const string& extension)
    :name(name),location(location), extension(extension)
{
}

string Object::get_name() const
{
    return this->name;
}

string Object::get_location() const
{
    return this->location;
}

string Object::get_extension() const
{
    return this->extension;
}

string Object::get_fullpath() const
{
    string fullPath = location + "/" + name + "." + extension;
    return fullPath;
}
