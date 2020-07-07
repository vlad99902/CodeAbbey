//
//  main.cpp
//  #32 (2)
//
//  Created by Владислав Легков on 08/02/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int q;
    cin >> q;
    int* array = new int[N];  //создание массива
    for (int i = 0; i < N; ++i)  //заполнение массива от 1 до N
    {
        array[i] = i+1;
    }
    for (int i = 0; i < N; ++i)
    {
        cout << array[i];
    }
    int w = 0; //переменная для проверки условия
    int count = 0; //счетчик для прохода
    int p = N;
    int count2 = 0;
    
    while (w != N-1)
    {
        for (int i = 0; i < p; ++i)
        {
            count++;
            if (count+1 == N)
            {
                array[i] = 0;
                w++;
                count = 0;
                count2++;
            }
        }
        
        
    }
    cout << endl;
    
    for (int i = 0; i < N; ++i)
    {
        cout << array[i];
    }

    return 0;
}
