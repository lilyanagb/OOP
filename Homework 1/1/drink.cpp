#include "drink.hpp"

Drink::Drink()
{
	name = nullptr;
	calories = 0;
	price = 0.0;
	quantity = 0.0;
}

Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price)
{
	int nameLength = my_strlen(init_name);
	name = new char[nameLength + 1];
	my_strcpy(init_name, name);

	this->calories = init_calories;
	this->quantity = init_quantity;
	this->price = init_price;
}

Drink::Drink(const Drink& copyFrom)
{
	int length = my_strlen(copyFrom.name);
	name = new char[length + 1];
	my_strcpy(copyFrom.name, name);

	calories = copyFrom.calories;
	quantity = copyFrom.quantity;
	price = copyFrom.price;
}

Drink& Drink::operator=(const Drink& rhs)
{
	if (this != &rhs) {
		if (name != nullptr) {
			delete[] name;
		}
		int length = my_strlen(rhs.name);
		name = new char[length + 1];
		my_strcpy(rhs.name,name);
		calories = rhs.calories;
		quantity = rhs.quantity;
		price = rhs.price;
		
	}
	return *this;
}

Drink::~Drink()
{
	delete[] name;
}

const char* Drink::get_name() const
{
	return this->name;
}

int Drink::get_calories() const
{
	return this->calories;
}

double Drink::get_quantity() const
{
	return this->quantity;
}

double Drink::get_price() const
{
	return this->price;
}

void Drink::set_name(const char* new_name)
{
		if (name != nullptr) {
			delete[] name;
	}
		int length = my_strlen(new_name);
		name = new char[length + 1];
		my_strcpy(new_name, name);
}

int Drink::my_strlen(const char* str)
{
	int count = 0;
	if(str != nullptr) {
		for (; str[count] != '\0'; count++) {}

		return count;
	}
	return 0;
}

char* Drink::my_strcpy(const char* str1, char* str2) {
	int i = 0;

	for (; str1[i] != '\0'; i++) {
		str2[i] = str1[i];
	}
	str2[i] = '\0';

	return str2;
}