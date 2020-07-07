//
//  main.cpp
//  #104  #104 Triangle Area
//
//  Created by Владислав Легков on 08/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>

using std::cin;
using std::cout;

double lenghtPoint (double x1, double x2, double y1, double y2)
{
    return sqrt(pow(x1-x2, 2)+pow(y1-y2,2));
}

double P2 (double a, double b, double c)
{
    return (a+b+c)/2;
}

double S (double a, double b, double c)
{
    double p = P2(a, b, c);
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int q = N;
    double *answers = new double [N];
    int i = 0;
    while (N != 0)
    {
        int x1,y1,x2,y2,x3,y3;
        cin >> x1;
        cin >> y1;
        cin >> x2;
        cin >> y2;
        cin >> x3;
        cin >> y3;
        double a,b,c;
        a = lenghtPoint(x1, x2, y1, y2);
        b = lenghtPoint(x1, x3, y1, y3);
        c = lenghtPoint(x2, x3, y2, y3);
        answers[i] =  S (a,b,c);
        //cout << answers[i] << "\t";
        ++i;
        --N;
    }
    
    for (int i = 0; i < q; ++i)
    {
        cout << std::setprecision (8) << answers[i] <<  "\t";
    }
    
    delete []answers;
    return 0;
}
