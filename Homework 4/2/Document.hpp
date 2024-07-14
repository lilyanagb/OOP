#pragma once
#include "Object.hpp"

class Document : public Object
{
public:
	Document(const string& name = "", const string& location = "", const string& extension = "");

	void write_line(const string& line);

	string read_line();
	string read_line(const unsigned line);

	string debug_print() const override;
	bool operator==(const Comparable*) const  override;
	bool operator!=(const Comparable*) const  override;

	string to_string() const override;
	void from_string(const string&) override;

	Object* clone() const override;
private:
	int pos;
	vector<string> collection;
};
