//
//  main.cpp
//  #30 Reverse String
//
//  Created by Владислав Легков on 29/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    char string[] = "";
    gets(string);
    for (int i = strlen(string)-1; i >= 0; --i)
    {
        cout << string[i];
    }
    return 0;
}
