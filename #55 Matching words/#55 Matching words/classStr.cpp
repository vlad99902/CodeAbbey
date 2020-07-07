//
//  classStr.cpp
//  #55 Matching words
//
//  Created by Владислав Легков on 08/05/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <stdio.h>
#include "classStr.h"

//конструктор класса Str_Words, объявление переменных
Str_Words :: Str_Words (string &line){
    this -> line = line;
    l_line = line.size();
}

string Str_Words::out_str()
{
    return searching_line;
}

//смена двух слов местами
void Str_Words::swap_two_words(const int first_index, const int second_index, string &line)
{
    string buf;
    string buf_2;
    //запись слов в буфер
    buf = line.substr(first_index,l_word);
    buf_2 = line.substr(second_index,l_word);
 
    line.erase(first_index,l_word);  //удаление слов
    line.insert(first_index, buf_2);     //вставка слов на места
    line.erase(second_index,l_word); //удаление слов
    line.insert(second_index, buf); //вставка слов на места
}


void Str_Words::selection_sort()
{
    long int num_of_words = searching_line.size()/l_word_with_space;
    string *array = new string[num_of_words];
    for (int i = 0; i < num_of_words; i++)
    {
        array[i] = searching_line.substr(i*l_word_with_space,l_word); //переписываем слова в массив слов
    }
    searching_line_selection_sort(array, num_of_words);
    
    searching_line.clear();
    

    for (int i = 0; i < num_of_words; i++)
    {
        searching_line += array[i] + ' ';
    }
    
    delete [] array;
}

void Str_Words::searching_line_selection_sort(string *array, const long int n)
{
    int min_word_i;
    
    for (int i = 0; i < n - 1; i++)
    {
        min_word_i = i; //присвоение минимальному эелементу i-го слова
        for (int j = i + 1; j < n; j++)
        {
            if (array[j]<array[min_word_i])
            {
                min_word_i = j;
            }
        }
        swap(array[min_word_i], array[i]);
    }
 
}


void Str_Words::result()
{
    for (int i = 0; i < line.size(); i+=l_word_with_space)
    {
        string buf = line.substr(i,l_word);
        size_t num_of_finding_word = line.find(buf,i+l_word_with_space); //size_t как тип .size
        if (num_of_finding_word != string::npos)
        {
            while (num_of_finding_word != string::npos)
            {
                line.erase(num_of_finding_word, l_word_with_space);
                num_of_finding_word = line.find(buf,num_of_finding_word);
            }
            searching_line.append(buf+' ');
        }
    }
}

