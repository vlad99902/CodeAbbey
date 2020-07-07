//
//  main.cpp
//  #31 Rotate string
//
//  Created by Владислав Легков on 30/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    
    //ofstream file("/Users/vlad99902ipad/Desktop/CodeAbbey/#31 Rotate string/out.txt");
    
    ifstream input ("/Users/vlad99902ipad/Desktop/CodeAbbey/#31 Rotate string/input.txt");
    ofstream out;
    out.open("/Users/vlad99902ipad/Desktop/CodeAbbey/#31 Rotate string/out.txt"); // открытие файла вывода
    
    string line;
    
    
    if (input.is_open())
    {
        int N = 0;
        getline(input,line);
        istringstream iss(line);
        iss >> N;     // считывание N
        while (getline(input,line))
        {
            string strq;  //строка
            int n; //количество символов для переноса
            istringstream iss(line);
            iss >> n >> strq;
            
            if (n >= 0) //если копирование из начала сроки
            {
                strq.insert(strq.size(), strq, 0, n);  //вырезание подстроки и вставка в конец
                strq.erase(0,n); //удаление начала строки
                out << strq << " "; //вывод результата в файл
            }
            
            else //если копирование из конца сроки
            {
                strq.insert(0, strq, strq.size()-abs(n), abs(n));
                strq.erase(strq.size()-abs(n),abs(n));
                out << strq << " ";
            }
            
            N--; //чтоы пользователь не ввел больше строк чем N
            if (N < 0)
            {
                out << "ERROR";
                break;
            }
                
        }
    }
    out.close();
    input.close();
    return 0;
}
