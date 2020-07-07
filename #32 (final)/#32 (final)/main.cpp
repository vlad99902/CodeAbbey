
#include <iostream>

using std::cin;
using std::cout;


int main(int argc, const char * argv[]) {
    int N, K;
    cin >> N;
    cin >> K;
    
    int *array = new int [N];
    for (int i = 0; i < N; ++i)
    {
        array[i] = i+1;
    }
    
    int j = N;
    int w = 1;
    int q = N;
    while (q != 1)
    {
        
        for (int i = 0; i < j; ++i)
        {
            
            if (w == K && array[i]!=0)
            {
                array[i] = 0;
                w = 1;
                --q;
            }
            if (array[i] == 0)
            {
                --w;
            }
            ++w;
        }
        
        //out
      /*  for (int i = 0; i < N; ++i)
        {
            cout << array[i] << "\t";
        }
        cout << "\n\n" << w << "\n"; */
    }
    for (int i = 0; i < N; ++i)
    {
        if (array[i] !=0 )
        {
            cout << array[i] << "\n";
            break;
        }
    }
    
    delete []array;
    return 0;
}
