//
//  main.cpp
//  #49  #49 Rock Paper Scissors
//
//  Created by Владислав Легков on 08/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::string;



int whoWins (string line)
{
    int a = 0, b = 0;
    long int s = line.size()-1;
    cout << "\n" << s << "\n";
    for (int i = 0; i < s-1; ++i)
    {
        cout << i << "\t";
        if ((line[i] == 'R' && line[i+1] == 'S') ||(line[i] == 'S' && line[i+1] == 'P')||(line[i] == 'P' && line[i+1] == 'R'))
        {
            a+=1;
        }
        else if ((line[i] == 'S' && line[i+1] == 'R') ||(line[i] == 'P' && line[i+1] == 'S')||(line[i] == 'R' && line[i+1] == 'P'))
        {
            b+=1;
        }
        
        i+=2;
    }
    cout << "\n" << a << "  " <<  b << "\n\n";
    if (a>b) return 1;
    else return 2;
}

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int q = N;
    
    int *answers = new int [N];
    
    int i = 0;
    while (N != 0)
    {
        string line;
        getline(cin, line);
        answers[i] = whoWins(line);
        ++i;
        --N;
        //cout << "\n" << line[2] << "\n";
        line.clear();
    }
    cout << "\n\n";
    for (int i = 0; i<q; ++i)
    {
        cout << answers[i] << "\t";
    }
    delete []answers;
    return 0;
}
