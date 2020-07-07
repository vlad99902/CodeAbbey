//
//  main.cpp
//  #48 collatz sequence
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

int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    int* array = new int [N];
    array = inarray<int>(N);
    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        count = 0;
        while (true)
        {
            
            if(array[i]%2 == 0){
                array[i] /=2;
            }
            else
            {
                array[i] = 3*array[i]+1;
            }
            count++;
            if(array[i]==1)
            {
                break;
            }
        }
        cout << count << "\t";
    }
    delete []array;
    
    return 0;
}
