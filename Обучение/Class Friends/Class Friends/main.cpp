//
//  main.cpp
//  Class Friends
//
//  Created by Владислав Легков on 23/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Auto
{
    friend void drive(Auto &);  //дружественные функции
    friend void setPrice(Auto &, int);
    
public:
    Auto(string autoName, int autoPrice) //конструктор класса
    {
        name = autoName;
        price = autoPrice;
    }
    
    string GetName() //получение public
    {
        return name;
    }
    
    int GetPrice()
    {
        return price;
    }
    
private:
    string name;
    int price;
};

void drive (Auto &a)  //дружественные функции работа
{
    cout << a.name << " is driven\n";
}

void setPrice (Auto &a, int price)
{
    if (price > 0)
    {
        a.price = price;
    }
        
}

int main(int argc, const char * argv[]) {
    Auto tesla ("Tesla", 5000);
    drive(tesla);
    setPrice(tesla, 8000);
    cout << tesla.GetName() << "  " << tesla.GetPrice() << "\n";
    return 0;
}
