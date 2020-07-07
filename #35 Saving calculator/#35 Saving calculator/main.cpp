//
//  main.cpp
//  #35 Saving calculator
//
//  Created by Владислав Легков on 30/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        double a,b,c;
        cin >> a >> b >> c;
        c *= 0.01;
        int count = 0;
        while (a <= b)
        {
            a += a*c;
            count++;
            
        }
        cout << endl << count << " ";
    }
    return 0;
}
