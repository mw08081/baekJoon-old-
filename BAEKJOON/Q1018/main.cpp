#include <iostream>
using namespace std;

int main()
{
    char arrCaseA[8][8] = 
    {
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    };
    char arrCaseB[8][8] = 
    {
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
        {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
        {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    };
    char input[50][50] = {0};
    int n, m, min = 33, cnt = 0;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> input[i][j];

    for (int i = 0; i < n - 7; i++)
    {
        for (int j = 0; j < m - 7; j++)
        {
            cnt = 0;
            for (int p = i; p < 8 + i; p++)
                for (int q = j; q < 8 + j; q++)
                    if (input[p][q] != arrCaseA[p - i][q - j])
                        cnt++;
            if(cnt < min)
                min = cnt;

            cnt = 0;
            for (int p = i; p < 8 + i; p++)
                for (int q = j; q < 8 + j; q++)
                    if (input[p][q] != arrCaseB[p - i][q - j])
                        cnt++;
            if(cnt < min)
                min = cnt;
        }
    }
    cout << min << '\n';

    return 0;
}