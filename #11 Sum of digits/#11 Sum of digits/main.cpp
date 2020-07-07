//
//  main.cpp
//  #11 Sum of digits
//
//  Created by Владислав Легков on 27/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        int a = 0, b = 0, c = 0;
        int sum = 0;
        int Ssum = 0;
        cin >> a >> b >> c;
        sum = a * b + c;
        while (sum != 0)
        {
            Ssum += sum % 10;
            sum /= 10;
        }
        cout << endl << Ssum << "\t";
    }
    
    
    return 0;
}
