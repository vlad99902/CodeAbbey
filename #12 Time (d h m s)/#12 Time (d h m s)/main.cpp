//
//  main.cpp
//  #12
//
//  Created by Владислав Легков on 27/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        int d = 0, h = 0, m = 0, s = 0;
        cin >> d >> h >> m >> s;
        int d1 = 0, h1 = 0, m1 = 0, s1 = 0;
        cin >> d1 >> h1 >> m1 >> s1;
        int sum1 = s + m * 60 + h * 60 * 60 + d * 24 * 60 * 60;
        int sum2 = s1 + m1 * 60 + h1 * 60 * 60 + d1 * 24 * 60 * 60;
        int Ssum = sum2 - sum1;
        double Sd = 0.0, Sh = 0.0, Sm = 0.0, Ss = 0.0;
        Sd = floor(Ssum / (24 * 60 * 60));
        Ssum -= Sd * 24 * 60 * 60;
        Sh = floor(Ssum / (60*60));
        Ssum -= Sh * 60 * 60;
        Sm = floor(Ssum / 60);
        Ss = Ssum-Sm * 60;
        cout << "(" << (int)Sd << "\t" << (int)Sh <<"\t" << (int)Sm <<"\t" << (int)Ss<< ")\t";
    }
    
    
    return 0;
}
