//10809

#include <iostream>
using namespace std;

int main()
{
    string str;
    int res[26];

    for (int i = 0; i < 26; i++)
        res[i] = -1;

    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (res[str[i] - 97] == -1)
            res[str[i] - 97] = i;
    }


    for (int i = 0; i < 26; i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}