//
//  main.cpp
//  struct test
//
//  Created by Владислав Легков on 25/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <cstring>

#include <cstdlib>

#include <fstream>

#include <cstdio>  //fgets ets

using namespace std;

struct Man{
       int birth_year;
       string name;
       double pay;
   };

void selectionSort (Man*, int);

int main(int argc, const char * argv[]) {
    const int l_name = 30 , l_year = 5, l_pay = 10;  //длина полей
    const int l_buf = l_name+l_year+l_pay;  // длина буфера не нужен т.к. буфер у нас строка а не char
    
    const int l_dbase = 100; //длина базы
    Man *dbase = new Man[l_dbase]; //массив структур для хранения базы
    char buf[l_buf]; // буфер для ввода строки из файла
    string name; //строка для фамилии сотрудника
    
    FILE* fin;
    
    if ((fin = fopen("/Users/vlad99902ipad/Desktop/CodeAbbey/Обучение/pavlovskaya/struct test 2/input.txt", "r")) == NULL)
    {
        puts("Ошибка открытия входного файла"); //выводит строку на стандартное устройство вывода
        return 1;
    }
   
    int i = 0;
    while (std::getline(fin, buf))  //feof пока не конец файла
    {
        if (i >= l_dbase)
        {
            cout << "Файл слишком длинный";
            return 1;
        }
        
        fgets(buf, l_name, fin); //запись строки в буфер, buf char
        for (int k = 0; k < l_name; k++)  //МОЖНО ПЕРЕПИСАТЬ ПО ДРУГОМУ? ИЛИ ПРОСКАНИРОВАТЬ ИЗ ФАЙЛА КЛАСС string
        {
            dbase[i].name[k] = buf[k];
        }
        cout << dbase[i].name << endl;
        dbase[i].birth_year = atoi(&buf[l_name]);
        dbase[i].pay = atof(&buf[l_name+l_year]);
      
        i++;
    }
    int n_record = i, n_man = 0;  //n_rec сколько реально человек в базе
    double mean_pay = 0;
    while (true)  //бесконечный цикл
    {
        cout << "Введите фамилию или слово end: ";
        cin >> name;
        if (name == "end")  //выход из цикла
            break;
        bool not_found = true;  //флаг поиска сотрудника
        for (int i = 0; i < n_record; i++)  //проход по массиву структур
        {
            if (dbase[i].name.find(name) == 0)  //если фамилия равна искомой
            {
                if (dbase[i].name[name.size()] == ' ')  //если после фамилии пробел
                {
                    cout << "name is " << dbase[i].name << "  birth year: " << dbase[i].birth_year << "  pay: " << dbase[i].pay << "\n";
                    n_man++;  //счетчик человек
                    mean_pay+= dbase[i].pay;  //сумма окладов
                    not_found = false;  //флаг
                    
                }
            }
        }
        if (not_found)
            cout << "Такого сотрудника нет\n";
        
    }
    
    
    //сортировка
    
    ofstream fout ("/Users/vlad99902ipad/Desktop/CodeAbbey/Обучение/pavlovskaya/struct test/output.txt");
    if (!fout)
    {
        cout << "Ошибка открытия файла вывода";
        return 1;
    }
    
    if (n_man > 0)
    fout << "Средний оклад: " << mean_pay/n_man << endl;   //вывод среднего оклада если сотрудники найдены
    
    selectionSort(dbase, n_record);
    
    for ( int i = 0; i < n_record ; i++ ) {
        fout << dbase[i].name << dbase[i].birth_year << ' ' << dbase[i].pay << endl;
    }
    
    delete []dbase;
    
    fout.close();
    
    fclose(fin);
    
    return 0;
}

void selectionSort (Man* dbase, int n_record)
{
    for (int i = 0; i < n_record-1; i++)
    {
        int i_min = i;
        for (int j = i + 1; j < n_record; j++){
            if (dbase[j].birth_year < dbase[i_min].birth_year)
            {
                i_min = j;
            }
        }
        swap(dbase[i],dbase[i_min]);
    }
}
