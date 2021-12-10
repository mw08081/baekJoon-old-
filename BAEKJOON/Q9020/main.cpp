#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;

    bool * arr = new bool[10001];
    fill_n(arr, 10001, 1);
    arr[0] = arr[1] = false;
    for (int i = 2; i < 10001; i++)
        if(arr[i] == true)
            for (int j = i * i; j < 10001; j+=i)
                arr[j] = false; 
                
    for (int i = 0; i < T; i++)
    {
        int a, b;
        int minDiff = 10000;
        
        int n;
        cin >> n;

        for (int i = 2; i < n / 2 + 1; i++)
        {
            if(arr[i] != true)
                continue;

            if(arr[n - i] == true)
            {
                a = i;
                b = n - i;

                if(abs(a - b) < minDiff)
                    minDiff = abs(a - b);
            }
        }
        cout << a << " " << b << '\n';
    }
    return 0;
}