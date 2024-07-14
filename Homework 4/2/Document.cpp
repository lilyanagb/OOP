#include "Document.hpp"


Document::Document(const string& name, const string& location, const string& extension)
	:Object(name,location,extension)
{
	pos = 1;
}

void Document::write_line(const string& line)
{
    collection.push_back(line);

}

string Document::read_line()
{
	int size = collection.size();
	if (size < pos) {
		throw out_of_range ("Out of range");
	}

	return collection[(pos++) -1];
	}

string Document::read_line(const unsigned line)
{
	
	const unsigned int size = collection.size();
	if (size < line || line<1) {
		throw out_of_range ("Out of range");
	}
	pos = line;

	return collection[(pos++)-1];
}

string Document::debug_print() const
{
	stringstream sw;
	string stringword;

	for (size_t i = 0; i <collection.size(); i++)
	{
		sw << "Line "<<i+1<<":"<<collection[i] << endl;
	}
	stringword = sw.str();

	return stringword;
}

bool Document::operator==(const Comparable* comp)const
{
		Comparable* compV = const_cast<Comparable*>(comp);
		auto compValue = dynamic_cast<Document*>(compV);
		if(compValue){
		if (collection.size() != compValue->collection.size()) {
			return false;
		}
		for (size_t i = 0; i < collection.size(); i++) {
			if (collection[i].compare(compValue->collection[i]) != 0) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool Document::operator!=(const Comparable* comp)const
{
		Comparable* compV = const_cast<Comparable*>(comp);
		auto compValue = dynamic_cast<Document*>(compV);
		if (compValue) {
		if (collection.size() != compValue->collection.size()) {
			return true;
		}
		for (size_t i = 0; i < collection.size(); i++) {
			if (collection[i].compare(compValue->collection[i]) != 0) {
				return true;
			}
		}
		return false;
	}
	
		return true;
}

string Document::to_string() const
{
	string myLine;
	string forName = get_name();
	string forLocation = get_location();
	string forExtension = get_extension();

	stringstream sw;
	string stringword;

	sw << forName << endl << forLocation << endl << forExtension << endl;
	for (size_t i = 0; i < collection.size(); i++)
	{
		sw << collection[i] << endl;
	}
	stringword = sw.str();

	return stringword;
}

void Document::from_string(const string& s) 
{
	collection.clear();
	string temp = "";
	int count = 0;
	

	for (size_t i = 0; i < s.length(); ++i) {

		if (s[i] == '\n') {
		count++;
			if (count <4 || temp=="") {
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
				collection.push_back(temp);
				temp = "";
		}
		else {
			temp.push_back(s[i]);
		}

	}
}

Object* Document::clone() const
{
	return new Document(*this);
}
