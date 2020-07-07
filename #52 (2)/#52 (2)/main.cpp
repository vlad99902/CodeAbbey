//
//  main.cpp
//  #52 (2)
//
//  Created by Владислав Легков on 30/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
//#include <cctype>
//#include <sstream>

#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
   // ofstream file("/Users/vlad99902ipad/Desktop/CodeAbbey/#52 (2)/out.txt");
    
    ofstream out;
    out.open("/Users/vlad99902ipad/Desktop/CodeAbbey/#52 (2)/out.txt");
    
    int N = 0;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if (c == sqrt(a*a + b*b))
        {
            out << "R ";
        }
        else if (c > sqrt(a*a + b*b))
        {
            out << "O ";
        }
        else
        {
            out << "A ";
        }
    }
    out.close();
    return 0;
}
