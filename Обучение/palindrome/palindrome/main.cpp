//
//  main.cpp
//  palindrome
//
//  Created by Владислав Легков on 09/07/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    string str = "tenfet";
    size_t strLength = str.size();
    
    bool answer = false;
    
    int right = ceil(strLength/2.0);
    
    for (int i = 0; i < right; i++){
        if (str[i] == str[strLength - i - 1]){
            answer = true;
        }
        else {
            answer = false;
            break;
        }
    }
    
    answer ? cout << "YES\n" : cout << "NO\n";
    return 0;
}
