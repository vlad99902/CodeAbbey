//
//  main.cpp
//  Class struct
//
//  Created by Владислав Легков on 24/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//
#pragma pack(1)

#include <iostream>
#include <string>

#include <cmath>

using namespace std;

struct work
{
    float first;
    int second;
    
    work (float first,  int second);
    void read ();
    void display () const;
};

void work::display() const
{
    cout << pow(first,second);
}

void work::read()
{
    cout << "Enter 1st number: ";
    cin >> first;
    cout << "Enter 2nd number: ";
    cin >> second;
    cout << endl;
}

work::work (float first,  int second)
{
    cout << "constructor called\n";
    
    /*
    if (first < 2000000)
        this -> first = first;
    
    if (second < 10)
        this -> second = second;*/
    
}

int main(int argc, const char * argv[]) {
    work one(2,2);
    //one.read();
    one.display();
    return 0;
}
