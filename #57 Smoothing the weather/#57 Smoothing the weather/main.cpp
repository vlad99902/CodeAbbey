//
//  main.cpp
//  #57 Smoothing the weather
//
//  Created by Владислав Легков on 30/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <iomanip>

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
        cout << setprecision (14) << array[i] << "  ";
    }
}


int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    double* array = NULL;
    array = inarray<double>(N);
    double* answers = new double [N];
    answers [0] = array[0];
    answers [N-1] = array[N-1];
    
    for (int i = 1; i < N-1; ++i)
    {
        answers[i] = (array[i-1]+array[i]+array[i+1])/3.0;
    }
    
    outarray(answers, N);
    delete []answers;
    delete []array;
    return 0;
}
