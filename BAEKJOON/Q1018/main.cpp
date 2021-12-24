#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    char ** board = new char*[n];
    char ** editBoard = new char*[n];

    for (int i = 0; i < n; i++)
    {
        board[i] = new char[m];
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
        editBoard[i] = new char[m];
    }

    int cnt = 0, min = 65;
    for (int i = 0; i < n - 7; i++)
    {
        for (int j = 0; j < m - 7; j++)
        {   
            for (int p = 0; p < n; p++)
                for (int q = 0; q < m; q++)
                    editBoard[p][q] = board[p][q];
            
            cnt = 0;
            for (int p = i; p < 8 + i; p++)
            {
                for (int q = j; q < 8 + j; q++)
                {
                    if(p > 0 && q == 0 && editBoard[p - 1][q] == editBoard[p][q])
                    {
                        cnt++;
                        if(editBoard[p][q] == 'B')
                            editBoard[p][q] = 'W';
                        else
                            editBoard[p][q] = 'B';
                    }

                    if(editBoard[p][q + 1] == editBoard[p][q])
                    {
                        cnt++;
                        if(editBoard[p][q + 1] == 'B')
                            editBoard[p][q + 1] = 'W';
                        else
                            editBoard[p][q + 1] = 'B';
                    }
                        
                }   
            }   
            if(cnt < min)
                min = cnt;
        }
    }
    for (int i = 0; i < n - 7; i++)
    {
        for (int j = m - 1; j > 6; j--)
        {   
            for (int p = 0; p < n; p++)
                for (int q = 0; q < m; q++)
                    editBoard[p][q] = board[p][q];
            
            cnt = 0;
            for (int p = i; p < 8 + i; p++)
            {
                for (int q = j; q > j - 7; q--)
                {
                    if(p > 0 && q == m - 1 && editBoard[p - 1][q] == editBoard[p][q])
                    {
                        cnt++;
                        if(editBoard[p][q] == 'B')
                            editBoard[p][q] = 'W';
                        else
                            editBoard[p][q] = 'B';
                    }

                    if(editBoard[p][q - 1] == editBoard[p][q])
                    {
                        cnt++;
                        if(editBoard[p][q - 1] == 'B')
                            editBoard[p][q - 1] = 'W';
                        else
                            editBoard[p][q - 1] = 'B';
                    }
                        
                }   
            }   
            if(cnt < min)
                min = cnt;               
        }
    }
    cout << min << '\n';

    return 0;
}