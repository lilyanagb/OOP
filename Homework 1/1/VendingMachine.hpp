#pragma once
#include "drink.hpp"

class VendingMachine
{
    public:
        VendingMachine();
        VendingMachine(const VendingMachine& from);
        VendingMachine& operator=(const VendingMachine& from);

        bool add_drink(const Drink& to_add);
        int buy_drink(const char* drink_name, const double money);

        double get_income() const;
        ~VendingMachine();
    private:
        int my_strlen(const char*);

        int count;
        double income;
        Drink* drink;
};

