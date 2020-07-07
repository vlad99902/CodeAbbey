//
//  main.cpp
//  #44 Double Dice Roll
//
//  Created by Владислав Легков on 08/04/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
using std::cin;
using std::cout;

int random (int a)
{
    a %= 6;
    ++a;
    return a;
}

int main(int argc, const char * argv[])
{
    int N,a,b;
    cin >> N;
    int *answers = new int[N];
    int i = 0;
    while (N > 0)
    {
        cin >> a;
        cin >> b;
        answers[i] = random(a)+random(b);
        ++i;
        --N;
    }
    for (int j = 0; j < i; ++j)
    {
        cout << answers[j] << "\t";
    }
    cout << "\n";
    delete []answers;
    return 0;
}
