#pragma once
#include "Comparable.hpp"
#include "Debug.hpp"
#include "Serializable.hpp"

#include <vector>
#include <iostream>     
#include <stdexcept>
#include <fstream>
#include <sstream>

class Object : public Comparable, public Debug, public Serializable
{
public:
	Object(const string& name = "", const string& location = "", const string& extension = "");
	virtual ~Object() = default;

	string get_name() const;
	string get_location() const;
	string get_extension() const;
	string get_fullpath() const;

	virtual Object* clone() const = 0;

protected:
	string name;
	string location;
	string extension;
};

