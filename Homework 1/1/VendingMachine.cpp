#include "VendingMachine.hpp"

VendingMachine::VendingMachine()
{
    count = 0;
    income = 0.0;
    drink = new Drink[100];
}

VendingMachine::VendingMachine(const VendingMachine& from)
{
   this->count = from.count;
   drink = new Drink[from.count];
   
    for (int i = 0; i < count; i++) {
        drink[i] = from.drink[i];
    }
  
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from)
{
    if (this != &from) {
        delete[] drink;
        this->count = from.count;
        
        drink = new Drink[from.count];
       
        for (int i = 0; i < count; i++) {
            drink[i] = from.drink[i];
        }
    }
    return *this;
}

bool VendingMachine::add_drink(const Drink& to_add)
{
    bool isHere = 0;
    int length = my_strlen(to_add.get_name());
    int i = 0;
    for (; i < count; i++) {
        for (int j = 0; j < length; j++) {
            if (drink[i].get_name()[j] == to_add.get_name()[j]) {
                isHere = 1;
            }
            else {
                isHere = false;
                break;
            }
       
        }
        if (!isHere) {
            break;
        }
    }
    if (!isHere) {
        drink[i] = to_add;
        count++;
        return true;
    }
    return false;
}

int VendingMachine::buy_drink(const char* drink_name, const double money)
{
    bool isHere = 0;
    int deletedElementIndex;
    int i = 0;
    int length = my_strlen(drink_name);
    for (; i < count; i++) {
        for (int j = 0; j < length; j++) {
            if (drink[i].get_name()[j] == drink_name[j]) {
                isHere = 1;
            }
            else {
                isHere = 0;
                break;
            }
        }
        if (isHere) {
            deletedElementIndex = i;
            break;
        }
            
    }
    int j = 0;
    if (isHere) {
        if (money >= drink[i].get_price()) {
            income += money;
            
            Drink* newData = new Drink[count];
            for (int i = 0; i < count; i++) {
                newData[i] = drink[i];
            }
            
            for (int i = 0; i < count; i++) {
                if (i == deletedElementIndex) {
                    deletedElementIndex = -2;
                    continue;
                }
                drink[j] = newData[i];
                j++;
            }
            count--;
            delete[] newData;
            return 0;
        }
        else if (money < drink[i].get_price()) {
            income += money;
            return 1;
        }
    }
    income += money;
        return 2;
    
}

double VendingMachine::get_income() const
{
    return income;
}

VendingMachine::~VendingMachine()
{
    delete[] drink;
}

 int VendingMachine::my_strlen(const char* str)
{
    int i = 0;
    for (; str[i] != '\0'; i++) {}
    return i;
}
