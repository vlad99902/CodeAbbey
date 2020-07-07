//
//  main.cpp
//  #81 Bit Count
//
//  Created by Владислав Легков on 31/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>

using namespace std;


template <typename T>
void outarray (T* array, int N)
{
    for (int i = 0; i < N; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    long int N;
    cin >> N;

    for (int k = 0; k< N; ++k)
    {
        long int  M;
        cin >> M;
        int array[32];
        if (M >= 0)
        {
            int i = 0;
            while (M > 0)
            {
                array[i] = M%2;
                M/=2;
                i++;
            }
            int count = 0;
            for (int j = i-1;j >= 0;--j)
            {
                if (array[j] == 1)
                {
                    count++;
                }
            }
            cout << count << " ";
        }
        else if (M < 0)
        {
            M*=-1;
            
            int i = 0;
            while (M > 0)
            {
                array[i] = M%2;
                M/=2;
                i++;
            }
            
            
            int ar [32];
            int j = i-1;
            
            for (int q = 0; q<32; ++q)
            {
                ar[q] = 0;
            }
            

            for (int q = 32-i; q<32; ++q)
            {
                ar[q] = array[j];
                j--;
            }
            
           // outarray(ar, 32);
            
            for (int j = 0 ; j < 32 ;++j)
            {
                if (ar[j] == 1)
                {
                    ar[j] = 0;
                }
                else
                {
                    ar[j] = 1;
                }
            }
            
            //outarray(ar, 32);
            
            for (int q = 31; q >= 0; --q)
            {
                if (ar[q] == 1)
                {
                    ar[q] = 0;
                    
                }else if (ar[q] == 0)
                {
                    ar[q] = 1;
                    break;
                }
                
            }
            
            //outarray(ar, 32);
            
            int count = 0;
            
            for (int j = 0; j < 32;++j)
            {
                if (ar[j] == 1)
                {
                    count++;
                }
            }
            cout << count << " ";
        }
    }
    return 0;
}
