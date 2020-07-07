//
//  main.cpp
//  pav_struct_1
//
//  Created by Владислав Легков on 24/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

struct Student {
    string name;
    int GroupNumber;
    int Marks [5];
    
};

int main(int argc, const char * argv[]) {
   
    const int D_Base = 100; //размер массива структур
    Student Base [D_Base]; //массив структур
    
    //cin.getline ( Base[0].name);
    cin >> Base[0].GroupNumber;
    cout << Base[0].name << "  " << Base[0].GroupNumber;
    return 0;
}
