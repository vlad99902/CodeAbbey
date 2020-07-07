//
//  main.cpp
//  class test
//
//  Created by Владислав Легков on 23/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    
    Person (string, int);
    void move();
    
    string GetName ();
    int GetAge ();
    void SetAge(int);
    
private:
    string name;
    int age;
};

void Person::SetAge(int a)
{
    if (a > 0 && a < 100)
        age = a;
}

int Person::GetAge()
{
    return age;
}

string Person:: GetName()
{
    return name;
}

Person :: Person (string a, int b)
{
    name = a;
    age = b;
}

void Person :: move ()
{
    cout << name << " is Mooving\n";
}

int main(int argc, const char * argv[]) {
    
    Person first ("Vlad", 21);
    //person.name = "Vlad";
    cout << first.GetName() << "  " << first.GetAge() << "  ";
    first.move();
    return 0;
}
