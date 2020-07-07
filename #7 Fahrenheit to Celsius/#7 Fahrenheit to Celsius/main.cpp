//
//  main.cpp
//  #7 Fahrenheit to Celsius
//
//  Created by Владислав Легков on 27/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <cmath>

int main(int argc, const char * argv[]) {
    int N = 0;
    std :: cin >> N;
    int a = 0;
    double b = 0;
    double c = (double)5/9;
    for (int i = 0; i < N; ++i)
    {
        std :: cin >> a;
        b = round((a-32)*c);
        std :: cout << (int)b << "\t";
    }
    return 0;
}
