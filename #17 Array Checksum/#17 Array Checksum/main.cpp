//
//  main.cpp
//  #17 Array Checksum
//
//  Created by Владислав Легков on 27/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

template <typename T> T* inarray (int N)
{
    T* array = new T (N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
        
    }
    return array;
}

int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    long int* array = new long int [N];
    array = inarray<long int>(N);
    
    long int res = 0;
    int seed = 113;
    long int mod = 10000007;
    for (int i = 0; i < N; ++i)
    {
        res = ((res + array[i]) * seed) % mod;
    }
    cout << endl << res;
    delete []array;
    return 0;
}
//если ответ неверный проверяй формат данных!
