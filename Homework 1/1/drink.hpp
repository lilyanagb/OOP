#pragma once

class Drink
{
public:
    Drink();
    Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price);
    Drink(const Drink&);
    Drink& operator=(const Drink&);
    ~Drink();

    const char* get_name() const;
    int get_calories() const;
    double get_quantity() const;
    double get_price() const;

    void set_name(const char* new_name);
private:
    int my_strlen(const char*);
    char* my_strcpy(const char*, char*);

    char* name;
    double quantity;
    int calories;
    double price;
};

