//
//  main.cpp
//  struct test 2
//
//  Created by Владислав Легков on 25/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <cstring>

#include <cstdlib>

#include <fstream>


using namespace std;

struct Student {
    string name;
    int group_num;
    int marks[5];
};

void output (Student*, int);
void SelectionSort (Student*, int);
void pop_back (Student*&, int &, const int);
float averagemark (int*, const int);
void outavermark (Student*, const int);// float(*)(int*,const int));

int main(int argc, const char * argv[]) {
    int l_dbase = 100;
    Student *dbase = new Student[l_dbase];
    
    int l_name = 30;
    int l_group_num = 3;
    
    //открытие файла ввода
    ifstream fin ("/Users/vlad99902ipad/Desktop/CodeAbbey/Обучение/pavlovskaya/students struct/input.txt");
    if (!fin)
    {
        cout << "Файл не может быть открыт\n";
        return 1;
    }
    
    //считывание начальных данных из файла
    
    string buf; //буфер
    int i = 0; //счетчик
    while (getline(fin,buf)) { //проход по данным из файла
        if (i > l_dbase){          //если файл слишком длинный выводить ошибку
            cout << "Файл слишком длинный\n";
            return 1;
        }
        dbase[i].name = buf.substr(0,l_name);
        dbase[i].name[l_name] = '\0';
        dbase[i].group_num = atoi(&buf[l_name]);
        
        for (int k = 0; k < 5; k++){
            dbase[i].marks[k] = atoi(&buf[l_name+l_group_num+k]);
        }
        i++;
    }
    
    int r_size = i; //real size of array
    output(dbase, r_size); //вывод массива структур
    
    cout << "---------------------------------Добавление записи---------------------------------\n";
    cout << "Введите ФИО, номер группы и 5 оценок: \nДля остановки ввода введите end\n";
    while(getline(cin, buf)){
        
        if (buf == "end\0")
        {
            break;
            
        } else {
            int is_space = 0;  //флаг для отбрасывания первого пробела
            int new_name_size = 0;
            for (int j = 0; j < buf.size(); j++){
                if (buf[j] == ' ')
                {
                    is_space++;
                   
                }
                if (buf[j] == ' ' && is_space == 2)
                {
                    new_name_size = j;
                    break;
                }
            }
            
            dbase[r_size].name = buf.substr(0,new_name_size);
            dbase[r_size].group_num = atoi(&buf[new_name_size]);
            for (int k = 0; k < 5; k++){
                dbase[r_size].marks[k] = atoi(&buf[new_name_size+3+k]);
            }
            
            //установка правильного количества пробелов
            while (new_name_size != l_name)
            {
                dbase[r_size].name += ' ';
                new_name_size++;
            }
            r_size++;
        }
    }
    
    output(dbase, r_size);
    
    cout << "---------------------------------Сортировка---------------------------------\n";
    SelectionSort(dbase, r_size);
    output(dbase, r_size);
    
    cout << "---------------------------------Удаление записи---------------------------------\n";
    cout << "Введите номер записи, которую вы хотите удалить: ";
    
    string del_num;
    int del_num_int;
    while (true)  //проверка на ввод числа
    {
        cin >> del_num;
        del_num_int = atoi(&del_num[0]);
        if (del_num_int == 0 && del_num[0] != '0')
        {
            cout << "\nFATAL ERROR. Enter only number\n";
        }
        else break;
    }
    
    pop_back(dbase, r_size, del_num_int-1);  //num -1 потому что номер по нейминку пользователя
    output(dbase, r_size);
    
    cout << "---------------------------Средняя оценка больше 4.0---------------------------\n";
    outavermark(dbase, r_size);
    
    
    fin.close();
    delete [] dbase;
    return 0;
}

void output (Student* dbase, const int r_size)
{
    for (int i = 0; i < r_size; i++){
        cout << i+1 << " Name: " << dbase[i].name << " group number: " << dbase[i].group_num <<
        " murks: ";
        for (int k = 0; k < 5; k++){
            cout << dbase[i].marks[k] << " ";
        }
        cout << endl;
    }
}

void SelectionSort (Student* dbase, const int l_dbase)
{
    for (int i = 0; i < l_dbase-1; i++)
    {
        int i_min = i; //номер минимаьного элемента
        for (int j = i + 1; j < l_dbase; j++)
        {
            if (dbase[j].group_num < dbase[i_min].group_num )
            {
                i_min = j;
            }
        }
        swap (dbase[i],dbase[i_min]);
    }
}

void pop_back (Student *&dbase, int &r_size, const int del_num){
    if (del_num > r_size)
    {
        cout << "\nERROR. Вы ввели номер, которого нет в базе\n";
    } else
    {
        r_size--;
        Student *newarray = new Student[r_size];
        bool on_del_el = false; //флаг прохода по удаляемой строке
        for (int i = 0; i < r_size; i++)
        {
            if (i == del_num)
            {
                on_del_el = true;
                newarray[i] = dbase[i+1];
            }
            
            if (on_del_el == false)
            {
                newarray[i] = dbase[i];
            } else {
                newarray[i] = dbase[i+1];
            }
        }
        
        delete [] dbase;
        dbase = newarray;
        
    }
}

float averagemark (int array[], const int n)
{
    int array_sum = 0;
    for (int i = 0; i < n; i ++){
        array_sum += array[i];
    }
    return (array_sum/(float)n);
}

void outavermark (Student *dbase, const int r_size)//float (*averagemark)(int*, const int))
{
    bool is_good_single = false;
    for (int i = 0; i < r_size; i++)
    {
        if (averagemark(dbase[i].marks,5)>4.0)
        {
            is_good_single = true;
            cout << i+1 << " Name: " << dbase[i].name << " group number: " << dbase[i].group_num <<
            " average murks: " << averagemark(dbase[i].marks,5) << endl;
        }
    }
    if (is_good_single == false)
        cout << "Таких учеников нет\n";
}
