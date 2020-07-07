//
//  main.cpp
//  #20 Vowel Count
//
//  Created by Владислав Легков on 29/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    int N = 0;
    cin >> N;
    char string[] = "";
    char check[] = {'a','o','u','i','e','y','\0'};
    for (int i = 0; i < N; ++i)
    {
        int count = 0;
        gets(string);
        for (int j = 0; j < strlen(string); ++j)
        {
            for (int k = 0; k<6; ++k)
            {
                if (string[j] == check[k])
                {
                    count++;
                    break;
                }
            }
        }
        //cout << string;
        cout << count << "\t";
    }
    
    //лучше сделать подсчет (проверку) с помощью встроенной функции
    return 0;
}
