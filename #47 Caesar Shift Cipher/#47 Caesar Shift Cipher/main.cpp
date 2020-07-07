//
//  main.cpp
//  #47 Caesar Shift Cipher
//
//  Created by Владислав Легков on 09/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

//#include "pch.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;



int read_num_and_swipe (ifstream &fin, int &n, int &swipe){  //чтение количества элементов и размера сдвига
    string line;
    getline (fin,line);
    n = atoi(&line[0]);
    swipe = atoi(&line[2]);
    if (n == 0 || swipe == 0)     //если возвращается 0, ввод некорректен
        return 0;
    return 10;
}

//#include "global_functions.h"

int main(int argc, const char * argv[])
{
    ifstream fin ("/Users/vlad99902ipad/Desktop/CodeAbbey/#47 Caesar Shift Cipher/input.txt");
    ofstream output;
    output.open("/Users/vlad99902ipad/Desktop/CodeAbbey/#47 Caesar Shift Cipher/output.txt");
    
    int input;
    int n;  //количество текстов
    int swipe;  //сдвиг
    input = read_num_and_swipe(fin, n, swipe);
    if (input == 0){
        cout << "FATAL INPUT ERROR\n";
        return 1;
    }
    
    fin.close();
    output.close();
    
    return 0;
}
