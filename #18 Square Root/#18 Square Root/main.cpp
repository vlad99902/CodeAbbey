//
//  main.cpp
//  #18 Square Root
//
//  Created by Владислав Легков on 29/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <iomanip>

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

int main(int argc, const char * argv[]) {
    int M = 2;
    int N = 0;
    cin >> N;
    int **array;             //создание нового массива
    
    array = intwoarray<int>(N, M);
    
    for (int i = 0; i < N; ++i)
    {
        double res = 1.0;
        for (int k = 0; k < array[i][1]; ++k)
        {
            res=(res + (double)array[i][0]/res)/(double)2;
            
        }
        cout << setprecision(12) << (double)res <<  endl;
    }
    Clear2Array(array, N);
    return 0;
}
