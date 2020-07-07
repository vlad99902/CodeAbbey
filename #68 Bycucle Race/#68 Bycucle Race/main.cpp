//
//  main.cpp
//  #68 Bycucle Race
//
//  Created by Владислав Легков on 06/02/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    int  N;
    cin >> N;
    cout << endl;
    while (N--)
    {
        double S, A, B;
        cin >> S >> A >> B;
        cout << setprecision(12) << A*S/(B+A) << "   ";
    }
    return 0;
}
