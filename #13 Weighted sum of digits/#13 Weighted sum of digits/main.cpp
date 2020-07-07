//
//  main.cpp
//  #13 Weighted sum of digits
//
//  Created by Владислав Легков on 27/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//


#include <iostream>
#include <cmath>

using namespace std;

int countt (int digit)
{
    int count = 0;
    while (digit != 0)
    {
        count++;
        digit /= 10;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        int sum = 0;
        int digit = 0;
        cin >> digit;
        int co = countt(digit);
        while (digit != 0)
        {
            sum += digit%10*co;
            digit /= 10;
            --co;
        }
        
        cout << sum << "\t";
    }

    return 0;
}
