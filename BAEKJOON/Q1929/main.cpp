#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    bool* arr = new bool[m + 1];
    fill_n(arr, m + 1, 1);
    arr[0] = arr[1] = false;

    for (int i = 2; i * i <= m; i++)
        if(arr[i] == true)
            for (int j = i * i; j <= m; j += i)
                arr[j] = false;
    
    for (int i = n; i <= m; i++)                                
        if (arr[i] == true)                                        
            cout << i << "\n";
    return 0;
}
