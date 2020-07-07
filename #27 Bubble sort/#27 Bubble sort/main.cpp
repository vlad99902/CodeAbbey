//
//  main.cpp
//  #27 Bubble sort
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
    int N = 0;
    cin >> N;
    int* array = new int [N];
    array = inarray<int>(N);
    int countswap = 0;
    int count = 0;
    
    while (true)
    {
        bool check = false;
        for (int j = 0; j < N-1; ++j)
        {
            if (array[j] > array[j+1])
            {
                swap(array[j], array[j+1]);
                countswap++;
                check = true;
               // cout << countswap << endl;
               // outarray(array, N);
            }
        }
        if (check == false)
        {
            count++;
            break;
        }
        count ++;
    }
    outarray(array, N);
    cout << endl << count << "\t"<<countswap;
    delete []array;
    return 0; //не очень понятное условие и пример в задаче
}
