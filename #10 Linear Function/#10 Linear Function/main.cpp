//
//  main.cpp
//  #10 Linear Function
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
        int x1, y1, x2, y2;
        double a;
        double b;
        cin >> x1 >> y1 >> x2 >> y2;
        a = round((y2-y1)/(x2-x1));
        b = round(y1 - x1 * a);
        cout << endl << "(" << (int)a << "\t" << (int)b << ")";
    }
    
    
    return 0;
}
