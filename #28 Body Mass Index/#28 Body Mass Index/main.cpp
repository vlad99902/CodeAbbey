//
//  main.cpp
//  #28 Body Mass Index
//
//  Created by Владислав Легков on 27/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//


#include <iostream>


using namespace std;

double BMI (double w, double h)
{
    return (w/(h*h));
}

int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        
        double w = 0.0;
        double h = 0.0;
        cin >> w >> h;
        double answer = BMI(w, h);
        if (answer<18.5)
        {
            cout << "under ";
        }else if (answer>=18.5 && answer < 25.0)
        {
            cout << "normal ";
        }
        else if (answer >= 25.0 && answer < 30.0)
        {
            cout << "over ";
        }else
            cout <<"obese ";
    }
    return 0;
}
