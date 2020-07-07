//
//  main.cpp
//  #23 bubble in array
//
//  Created by Владислав Легков on 29/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>

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

template <typename T>
void outarray (T* array, int N)
{
    for (int i = 0; i < N; ++i)
    {
        cout << array[i] << "\t";
    }
}

int main(int argc, const char * argv[]) {
    int N = 100;
    int* array = new int [N];
    int count = 0;
    int i = 0;
    while (count!=-1)
    {
        cin >> count;
        array[i] = count;
        i++;
    }
    count = 0;
   // outarray(array, i-1);
    for (int j = 0; j<i-2; ++j)
    {
        if (array[j]>=array[j+1])
        {
            swap(array[j], array[j+1]);
            count++;
        }
    }
    
    long int res = 0;
    int seed = 113;
    long int mod = 10000007;
    for (int j = 0; j < i-1; ++j)
    {
        res = ((res + array[j]) * seed) % mod;
    }
    //cout << endl;
    //outarray(array, i-1);
    cout << "\n" << count << " " << res;
    
    delete []array;
    
    return 0;
}
