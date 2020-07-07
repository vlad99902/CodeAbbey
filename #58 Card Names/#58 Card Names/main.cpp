//
//  main.cpp
//  #58 Card Names
//
//  Created by Владислав Легков on 20/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int mod (int);
int dev (int);
string result(int (*)(int), int (*)(int), int, const string[], const string[]);

int main(int argc, const char * argv[])
{
    string suits[4] = {"Clubs", "Spades", "Diamonds", "Hearts"};
    string ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    
    //считывание начальных данных
    int n = 0;
    cin >> n;
    int *array = new int [n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    
    //массив ответов
    string *answers = new string [n];
    
    //работа программы
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        answers[i] = result(dev, mod, array[i],suits,ranks);
        cout << answers[i] << "\t";
    }
    
    //вывод ответа
    cout << "\n\n";
    delete [] answers;
    delete [] array;
    return 0;
}

int mod (int a)
{
    return a%13;
}

int dev (int a)
{
    return a/13.0;
}

string result(int(*func1)(int), int(*func2)(int),int a, const string suits[], const string ranks[])
{
    int d = func1(a);
    int m = func2(a);
    return ranks[m] + "-of-" + suits [d];
}

