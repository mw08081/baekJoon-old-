#include <iostream>
using namespace std;

int main()
{
    string str;
    int cnt = 0, idx = 0;

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i];
        cnt++;

        if(cnt >= 10)
        {
            cnt = 0;
            cout << '\n';
        }        
    }
    return 0;
}