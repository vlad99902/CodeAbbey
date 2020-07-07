//
//  main.cpp
//  #19 Matching Brackets
//
//  Created by Владислав Легков on 09/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

#include <fstream>

using namespace std;

int main(int argc, const char * argv[])
{
    //ofstream file("/Users/vlad99902ipad/Desktop/CodeAbbey/#19 Matching Brackets/output.txt");
    
    ifstream input ("/Users/vlad99902ipad/Desktop/CodeAbbey/#19 Matching Brackets/input.txt");
    ofstream output;
    output.open("/Users/vlad99902ipad/Desktop/CodeAbbey/#19 Matching Brackets/output.txt"); // открытие файла вывода
    
    string line;
    
    if (input.is_open())
    {
        int N = 0;
        string line;
        getline(input, line);     // считывание N
        N = atoi(line.c_str());
        
        cout << "-----" << N << "______\n\n";
        
        int q = N;  //начальные сведения, колчество тест кейсов
        
        int *answers = new int [N]; //массив ответов
        
        string line2;
        bool a = true;
        
        while (getline(input,line2))
        {
            
        //считывание строки
            
            cout << line2 << "\t";
            
            stack <char> stack;
            
            stack.push('0');
            
            cout <<  line2.size() << "\t";
            
            
            
            for (int i = 0; i < line2.size(); ++i)   //проход по строке
            {
                if (line2[i] == '(' || line2[i] == '[' || line2[i] == '<' || line2[i] == '{')  //если скобка открывается - добавляем ее в стек
                {
                    stack.push(line2[i]);
                }
                else if ((line2[i] == ')' && stack.top() == '(') || (line2[i] == ']' && stack.top() == '[')||(line2[i] == '}' && stack.top() == '{')||(line2[i] == '>' && stack.top() == '<')) // если закрывается, а предыдущая открывается удаляем предудущую
                {
                    stack.pop();
                }
                else
                {
                    if (line2[i] == ')' || line2[i] == '(' || line2[i] == '{' || line2[i] == '}' || line2[i] == '[' || line2[i] == ']' || line2[i] == '<' || line2[i] == '>' )
                    {
                        a = false;
                        break;
                    }
                }
                
                cout << stack.top() ;
            }
            
            cout << "   " << stack.top() << "\n\n";
            
            if (stack.top() == '0' || stack.empty())
            {
                answers[N-q] = 1;
            } else
            {
                answers[N-q] = 0;
            }
            if (a == false)
            {
                answers[N-q] = 0;
            }
            
            a = true;
            
            --q;
            if(q == 0)
            {
                break;
            }
            
        }
        
        cout << "\n";
        
        for (int i = 0; i < N; ++i)    //вывод ответов
        {
            cout << answers[i] << "\t";
            output << answers[i] << " ";
        }
        
        cout << "\n\n";
        delete [] answers;
    }
    
    input.close();
    output.close();
    
    return 0;
}
