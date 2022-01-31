#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int res[10000] = {0};
    int n, tmp, max = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        res[tmp - 1]++;
        
        if(tmp > max)
            max = tmp;
    }

    for (int i = 0; i < max; i++)
        for (int j = 0; j < res[i]; j++)
            cout << i + 1<< '\n';
        
    return 0;
}