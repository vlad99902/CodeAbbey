//
//  main.cpp
//  #8 Arithmetic Progression
//
//  Created by Владислав Легков on 27/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int first;
        int step;
        int number;
        cin >> first;
        cin >> step;
        cin >> number;
        int sum = first;
        for (int j = 1; j < number; ++j)
        {
            sum += first + step*j;
        }
        cout << sum << "\t";
    }
    return 0;
}
