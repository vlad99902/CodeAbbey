//
//  classStr.h
//  #55 Matching words
//
//  Created by Владислав Легков on 08/05/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#ifndef classStr_h
#define classStr_h
#include "pch.h"

//класс

class Str_Words{
  
public:
    Str_Words (string &line);
    void result ();
    string out_str();
    
    void searching_line_selection_sort(string *, const long int n);
    void swap_two_words(const int first_index, const int second_index, string &line);
    void selection_sort();
    
private:
    string line;
    long int l_line;
    string searching_line;
    
protected:
    const int l_word = 3;
    const int l_word_with_space = l_word+1;
};

#endif /* classStr_h */
