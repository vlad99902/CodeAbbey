//
//  main.cpp
//  #24 Neumann's Random Generator
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
    for (int i = 0; i < N; ++i)
    {
        int count = 0;
        int Num1 = array[i];
        int Num2 = 0;
        int* answers = new int [200];
        bool a = true;
        while (a)
        {
            answers[count] = Num1;
            Num2 = Num1*Num1;
            Num2 /= 100;
            Num2 %= 10000;
           // cout << Num2 << endl;
            
            if ((Num1 == Num2)||(Num2 == array[i]))
            {
                count++;
                a = false;
                break;
            }
            else
            {
                for (int j = 0; j < count; ++j)
                {
                    if (Num2 == answers[j])
                    {
                        //count++;
                        a = false;
                        break;
                    }
                }
            }
            Num1 = Num2;
            count++;
        }
        cout << count << " ";
         delete []answers;
    }
   
    delete []array;
    return 0;
}
