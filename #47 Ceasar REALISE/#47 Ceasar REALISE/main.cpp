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

string decode_cesar (const string &line, const int n){ //декодирование
    
    //char buf;
    int new_symbol_code;
    long int l_line = line.size();
    string decode_str;
    //cout << (int)'A' << "  " << (int)'Z'; //тестовый вывод
    
    for (int i = 0; i<l_line; i++){
        if (line[i] == ' '){
            decode_str += ' ';
        }
        else {
            new_symbol_code = (int)line[i]-n;
            if (new_symbol_code < 65) //если код меньше 65 то
            {
                decode_str += static_cast<char>(90 - (65-new_symbol_code)+1);
            }
            else
                decode_str += static_cast<char>(new_symbol_code);
        }
    }
    
    decode_str[l_line-1] = '.';
    return decode_str;
}

int read_num_and_swipe (ifstream &fin, int &n, int &swipe){  //чтение количества элементов и размера сдвига
    string line;
    getline (fin,line);
    n = atoi(&line[0]);
    swipe = atoi(&line[4]);
    if (n == 0 || swipe == 0)     //если возвращается 0, ввод некорректен
        return 0;
    return 1;
}

//#include "global_functions.h"

int main(int argc, const char * argv[])
{
    ifstream fin ("/Users/vlad99902ipad/Desktop/CodeAbbey/#47 Ceasar REALISE/input.txt");
    ofstream fout;
    fout.open("/Users/vlad99902ipad/Desktop/CodeAbbey/#47 Ceasar REALISE/output.txt");
    
    int input;
    int n;  //количество текстов
    int swipe;  //сдвиг
    input = read_num_and_swipe(fin, n, swipe);
    if (input == 0){
        cout << "FATAL INPUT ERROR\n";
        return 1;
    }
    
    //test
    string line;
    while (getline(fin, line)){
    
        fout << decode_cesar(line,swipe) << "\n";
    }
    fin.close();
    fout.close();
    
    return 0;
}
