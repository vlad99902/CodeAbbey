//
//  main.cpp
//  #14 Modular Calculator
//
//  Created by Владислав Легков on 27/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>


using namespace std;

int main(int argc, const char * argv[]) {
    int n = 0;
    cin >> n;
    
    int a = 0;
    int* num = new int [n];
    char znaq[n];
    int i =0;
    
    while (true)
    {
        cin >> znaq[i];
        cin >> num[i];
        if (znaq[i] == '%')
        {
            a = num[i];
            break;
            
        }
        //cout << i << "  "<< znaq[i] << "  " << num[i] << endl;
        i++;
        
    }
   
    for (int j = 0; j <= i; ++j)
    {
        if (n>a)
                   n %= a;
        if (znaq[j] == '+')
        {
            {
                n += num[j];
            }
        }
        else if (znaq[j] == '*')
        {
            {
                n *= num[j];
            }
        }
       // cout << n << endl;
       
            
    }
    cout << endl << n%a;
    delete [] num;
    
    return 0;
}
