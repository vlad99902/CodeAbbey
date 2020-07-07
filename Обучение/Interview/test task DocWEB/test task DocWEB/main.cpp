//
//  main.cpp
//  test task DocWEB
//
//  Created by Владислав Легков on 07/07/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>

using std::cout;

/**
 Function to delete spaces from the end of string
 char *s - String by the char array
 */
void TrimRight (char *s){
    /**
     int length - variable to find array length
     */
    int length = 0;
    while (s[length] != '\0'){
        length++;
    }
    /**
     deleting end's symbols (spaces) in string
     */
    while ((unsigned int)s[length-1] == 32){
        s[length]='\0';
        length--;
    }
    /**
     set terminating zero on end last space position
     */
    s[length] = '\0';
}

int main(int argc, const char * argv[]) {
    char s[] = "sdvdsvsd sdvsd sdvsdv sdv                                  ";
    TrimRight(s);
    cout << "\n" << s;
    return 0;
}
