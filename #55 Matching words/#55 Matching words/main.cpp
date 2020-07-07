//
//  main.cpp
//  #55 Matching words
//
//  Created by Владислав Легков on 08/05/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include "pch.h"
#include "classStr.h"

int main(int argc, const char * argv[]) {
    
    ifstream fin ("/Users/vlad99902ipad/Desktop/CodeAbbey/#55 Matching words/input.txt");
    string line;
    getline(fin,line);
    Str_Words words (line);
    words.result();
    words.selection_sort();
    cout << "\n\n\n" << words.out_str();
    fin.close();
    return 0;
}
