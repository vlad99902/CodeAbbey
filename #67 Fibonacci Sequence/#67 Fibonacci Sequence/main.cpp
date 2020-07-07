#include <iostream>
#include <string>
#include "string"

using namespace std;

unsigned long int size (string a, string b)  //возвразает размер большей строки
{
    unsigned long int siz = 0;
    unsigned long int sizea = a.size();
    unsigned long int sizeb = b.size();
    
    if (sizea > sizeb)
    {
        siz = sizea;
    }
    else
    {
        siz = sizeb;
    }
    return siz;
}
string rever (string a)
{
    string b;
    int n = (int)a.size();
    for (int i = 0; i<=a.size();++i)
    {
        b[i]=a[n];
        n--;
        cout << b[i] << endl;
    }
    return b;
}
int main ()
{
    string a = "1234568";
    string b = "1232";
    
    int sizea = (int)a.size();
    int sizeb = (int)b.size();
    
    int siz = (int)size(a, b);
    
    
    string c;
    int n = (int)a.size();
    for (int i = 0; i<=a.size();++i)
    {
        b[i]=a[n];
        n--;
        cout << b[i] << endl;
    }
    
    cout << c << "\n\n";
    
    //b = rever(a);
    for (int i = 0; i < a.size(); ++i)
    {
        cout<<a[i];
    }

    
    int* result = new int[siz];
    int buf = 0;
    for (int i = siz; i >= 0 ; --i)
    {
        cout<< buf << endl;
        result[i] = ((int)a[i]+(int)b[i])%10 + buf;
        cout<<result[i] <<endl;
        buf = ((int)a[i]+(int)b[i])/10;
        cout << result << endl;
    }
    cout << result << endl << endl;
    cout << a[2] << endl;
  
    return 0;
}
