//
//  main.cpp
//  Class auto and person
//
//  Created by Владислав Легков on 24/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <string>

using std::cout;
using std::string;

class Auto; //так как person использует auto, auto нужно определить

class Person
{
public:
    Person (string n)  //конструктор класса
    {
        name = n;
    }
    
    void drive(Auto &);  //методы класса person
    void setPrice(Auto &, int);
    
private:
    string name;
    
};

class Auto
{
    //friend void Person::drive(Auto &); //дружественные функции класса auto
   // friend void Person::setPrice (Auto&, int);
    friend class Person; // или можно сделать весь класс дружественным
public:
    Auto (string autoName, int autoPrice)  //конструктор класса auto
    {
        name = autoName;
        price = autoPrice;
    }
    
    string GetName () //получение private переменных
    {
        return name;
    }
    
    int GetPrice ()
    {
        return price;
    }
    
private:
    string name;
    int price;
    
};

//методы описаны после класса auto т.k. они используют переменных класса auto

void Person::drive(Auto &a)
{
    cout << name << " drives " << a.name << "\n";
}

void Person::setPrice(Auto &a, int price)
{
    if (price > 0)
    {
        a.price = price;
    }
}

int main(int argc, const char * argv[]) {
    Auto car ("Tesla",5000);
    Person vladik ("Vlad");
    
    vladik.drive(car);
    vladik.setPrice(car, 8000);
    cout << car.GetName() << "  " << car.GetPrice() << "\n";
    return 0;
}
