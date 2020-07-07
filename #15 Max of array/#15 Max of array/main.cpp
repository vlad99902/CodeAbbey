//
//  main.cpp
//  #15 Max of array
//
//  Created by Владислав Легков on 27/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>

using namespace std;

void countMM (int* array,int N)
{
    int min = array[0];
    int max = array[0];
    for (int i = 1; i < N; i++)
    {
        if (array[i] < min){
            min = array[i];
        }
        if (array[i] > max){
            max = array[i];
        }
    }
    cout << endl << max << "\t" << min;
}

int* inarray (int N)
{
    int* array = new int (N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
        
    }
    return array;
}


int main() {
   /* int count = 1;
    for (int i = 0; i < 150; i++)
    {
        cout << count<<endl;
        count +=1;
    }
    int N = 150;
    int* array = new int [N];
    array = inarray(N);
    countMM(array, N);
    delete []array;*/
    int N = 300;
    int* array = new int (N);
    
    for (int i = 0; i < N; i++)
    {
        cin >> array[i];
        
    }
    int min = array[0];
    int max = array[0];
    for (int i = 1; i < N; i++)
    {
        if (array[i] < min){
            min = array[i];
        }
        if (array[i] > max){
            max = array[i];
        }
    }
    cout << endl << max << "\t" << min;
    delete []array;
    return 0;
}
