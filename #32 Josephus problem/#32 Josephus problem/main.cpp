//
//  main.cpp
//  #32 Josephus problem
//
//  Created by Владислав Легков on 30/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <vector> //библиотека векторов

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<int> vect(N); // создание вектора
    
    //выделение памяти под вектор
    
    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        vect[i] = count+1;
        count++;
       // cout << vect[i] << " ";
    }
    count = 0;
    
    while (vect.size()>1)
    {
        
        for (int i = 0; i < vect.size(); ++i)
        {
            count++;
            if (count == K)
            {
                vect.erase(vect.begin()+i);
                count = 1;
            }
                

        }
        cout << endl;
        for (int i = 0; i < vect.size(); ++i)
        {
            
            cout <<  vect[i] << " ";
        }
        
    }
    cout << endl << vect[0] << "\n";
    vect.clear();
    return 0;
}
