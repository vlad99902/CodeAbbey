//
//  main.cpp
//  testing modules
//
//  Created by Владислав Легков on 09/05/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <string>

#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    ifstream fin ("/Users/vlad99902ipad/Desktop/CodeAbbey/#55 Matching words/input.txt");
    string line;
    getline (fin,line);
    
    string buf = "def";
    cout << "\n" << line.find(buf);
    fin.close();
    return 0;
}
