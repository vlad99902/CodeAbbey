//
//  main.cpp
//  #21 array counters
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
    int M = 0;
    cin >> M;
    int* num = new int [M];
    for (int i = 0; i< M; ++i)
    {
        num[i] = i+1;
    }
    int* answers = new int [M];
    for (int i = 0; i< M; ++i)
    {
        answers[i] = 0;
    }
    int* array = new int [N];
    array = inarray<int>(N);
    for (int i = 0; i<N; ++i)
    {
        for (int j = 0; j<M;++j)
        {
            if (array[i] == num[j])
            {
                answers[num[j]-1]+=1;
                break;
            }
        }
    }
    outarray<int>(answers, M);
    delete []array;
    delete []answers;
    delete []num;
    return 0;
}
