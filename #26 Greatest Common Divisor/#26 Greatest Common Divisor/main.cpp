//
//  main.cpp
//  #26 Greatest Common Divisor
//
//  Created by Владислав Легков on 29/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename T> T** intwoarray (int N, int M)
{
    T** matrix;
    matrix = new T*[N];
    for (int i = 0; i < N; i++)
        matrix[i] = new T[M];
    
    for (int i = 0;i<N;++i)
        for (int j = 0; j<M; ++j)
            cin >> matrix[i][j];
    
    return matrix;
}

template <typename T> void outtwoarray (T** matrix, int N, int M)
{
    for (int i = 0;i<N;++i)
    {
        for (int j = 0; j<M; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
        
}

void Clear2Array (int** array, const int n)
{
    
    for (int i = 0; i < n; ++i)
    {
        delete []array[i];
    }
    delete []array;
  
}

int gcd (int a, int b)
{
    while (a!=b)
    {
        if (a>b)
        {
            a-=b;
        }
        else if (a<b)
        {
            b-=a;
        }
    }
    return a;
}

int lcm (int a, int b)
{
    return (a*b/gcd(a, b));
}

int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    int M = 2;
    int **array;             //создание нового массива
    array = intwoarray<int>(N, M);
    for (int i = 0; i< N; ++i)
    {
        cout << "(" << gcd(array[i][0], array[i][1]) << "\t" << lcm(array[i][0], array[i][1]) <<")" <<" ";
    }
    //outtwoarray(array, N, M);
    Clear2Array(array, N);
    return 0;
}
