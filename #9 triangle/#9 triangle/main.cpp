//
//  main.cpp
//  #8 Arithmetic Progression
//
//  Created by Владислав Легков on 27/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename T>
void outarray (T* array, int N)
{
    for (int i = 0; i < N; ++i)
    {
        cout << array[i] << "\t";
    }
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int* answers = new int [N];
    for (int i = 0; i < N; ++i)
    {
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
        if (a+b>c && a+c>b && b+c > a)
        {
            answers [i] = 1;
        }
        else{
            answers[i] = 0;
        }
        
    }
    outarray<int>(answers, N);
    delete []answers;
    return 0;
}
