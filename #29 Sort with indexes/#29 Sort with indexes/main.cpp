//
//  main.cpp
//  #29 Sort with indexes
//
//  Created by Владислав Легков on 29/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>

#include <iostream>

using namespace std;

template <typename T> T** intwoarray (int N, int M)
{
    T** matrix;
    matrix = new T*[N];
    for (int i = 0; i < N; i++)
        matrix[i] = new T[M];
    
    //for (int i = 0;i<N;++i)
        for (int j = 0; j<M; ++j)
            cin >> matrix[0][j];
    
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

int** sortt (int** array, int m)
{
    while (true)
    {
        bool check = false;
        for (int j = 0; j < m-1; ++j)
        {
            if (array[0][j] > array[0][j+1])
            {
                swap(array[0][j], array[0][j+1]);
                swap(array[1][j], array[1][j+1]);
                check = true;
            }
        }
        if (check == false)
        {
            
            break;
        }
    
    }
    
    return array;
}

int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    int** array;
    array = intwoarray<int>(2, N);
    for (int j = 0; j < N; j++)
    {
        array[1][j] = j+1;
    }
    int** matrix;
    matrix = new int*[2];
    for (int i = 0; i < 2; i++)
        matrix[i] = new int[N];
    matrix = sortt(array, N);
    outtwoarray(array, 2, N);
    for (int i = 0; i < 2; ++i)
    {
        delete []array[i];
    }
    delete []array;
   
    return 0;
}
