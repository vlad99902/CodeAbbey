//
//  main.cpp
//  test
//
//  Created by Владислав Легков on 11/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void goodmorning();
void goodevening();
void (*message(int))();

int main(int argc, const char * argv[]) {
    
   void(*action)();    // указатель на выбранную функцию
   action = message(3);
   action();       // выполняем полученную функцию
   return 0;
}

void (*message(int hour))()
{
    if (hour > 12)
        return goodevening;
    else
        return goodmorning;
}

void goodevening ()
{
    cout << "Good evening \n";

}

void goodmorning ()
{
    cout << "Good morning \n";
}
