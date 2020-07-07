//
//  main.cpp
//  #43
//
//  Created by Владислав Легков on 27/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int res = 0;
        double a = 0.0;
        cin >> a;
        res = (int)floor(a * 6) + 1;
        cout << res << "\t";
    }
    return 0;
}
