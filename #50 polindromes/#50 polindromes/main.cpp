//
//  main.cpp
//  #50 polindromes
//
//  Created by Владислав Легков on 30/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main(int argc, const char * argv[]) {
    int N = 0;
    cin >> N;
    ofstream out;
    out.open("/Users/vlad99902ipad/Desktop/CodeAbbey/#50 polindromes/out.txt"); // открытие файла вывода
    //ofstream file("/Users/vlad99902ipad/Desktop/CodeAbbey/#50 polindromes/input.txt");
    
    string line;
    ifstream input("/Users/vlad99902ipad/Desktop/CodeAbbey/#50 polindromes/input.txt"); // открытие файла ввода
    
    if (input.is_open()) //если файл ввода открылся
    {
        while (getline(input,line)) //считываем строку
        {
        
            for (int i = 0; line[i] != '\0'; ++i) //удаление знаков препинания, пробелов, и изменение регистров
            {
                if(ispunct(line[i]))
                {
                    line.erase(i,1);
                }
                if(line[i] == ' ')
                {
                    line.erase(i,1);
                }
                if (isalpha(line[i]))
                {
                    line[i] = tolower(line[i]);
                }
            }

            
            long int k = line.size()-1; //счетчик для проверки полиндромов
            
            bool check = true;
            for (int j = 0; j < line.size(); ++j)  // реализация проверки на полиндром
            {
                if (line[j] != line[k])
                {
                    check = false;
                    break;
                }
                k--;
            }
            
            if (check == true)  //вывод результата в файл
            {
                if (out.is_open())
                {
                    out << "Y ";
                }
            }
            else
            {
                if (out.is_open())
                {
                    out << "N ";
                }
            }
            
        }
    }
    
    input.close();
    out.close();
    
    return 0;
    //число количества строк вводится, но значения не имеет
}
