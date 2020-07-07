//
//  main.cpp
//  #41 Median of Three
//
//  Created by Владислав Легков on 27/01/2020.
//  Copyright © 2020 Владислав Легков. All rights reserved.
//

#include <iostream>
using namespace std;

/*int med (int a, int b, int c)  // мой метод
{
    int mid = a;
    if ((b <= mid && b>=c) || (b <= c && b>=mid))
    {
        mid = b;
    }
    if ((c >= b && c <= a)||(c >= a && c <= b))
        
    {
        mid = c;
    }
    
    return mid;
} */


int med (int a, int b, int c)   // лучший способ с помощью сортировки
{
    if (a > b)
    {
        swap(a, b);
    }
    if (b > c)
    {
        swap(b, c);
    }
    if (a > b)
    {
        swap(a, b);
    }
    return b;
}
int main(int argc, const char * argv[]) {
    
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << endl << med(a, b, c) << "\t";
    }
    return 0;
}
