#include <iostream>
using namespace std;

int main()
{
    int n = -1;
    bool * arr = new bool[246913];
    fill_n(arr, 246913, 1);

    arr[0] = arr[1] = false;
    for (int i = 2; i < 497; i++)
        if(arr[i] == true)
            for (int j = i * i; j < 246913; j+=i)
                arr[j] = false;   

    cin >> n;
    while(n != 0)
    {
        int cnt = 0;
        for (int i = n + 1; i <= 2 * n; i++)
        {
            if(arr[i] == true)
                cnt++;

        }
        cout << cnt << '\n';
        cin >> n;
    }
    return 0;
}