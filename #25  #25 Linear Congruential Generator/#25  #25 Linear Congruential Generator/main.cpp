//
//  main.cpp
//  #25  #25 Linear Congruential Generator
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

int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    int M = 5;
    int **array;             //создание нового массива
    array = intwoarray<int>(N, M);
    for (int i = 0; i < N; ++i)
    {
        while (true)
        {
            array[i][3] = (array[i][0] * array[i][3] + array[i][1])%array[i][2];
            array[i][4]--;
            if (array[i][4]==0)
            {
                cout << array[i][3] << " ";
                break;
            }
        }
        
    }
    cout << endl;
    //outtwoarray(array, N, M);
    Clear2Array(array, N);
    return 0;
}
