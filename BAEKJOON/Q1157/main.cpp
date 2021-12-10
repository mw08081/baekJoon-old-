#include <iostream>
using namespace std;

int main()
{
    int res[26] = { 0 };
    string str;
    cin >> str;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
            res[str[i] - 65]++;
        else
            res[str[i] - 97]++;
    }

    int max = 0;
    char idx = 0;
    bool isBoth = false;
    for (int i = 0; i < 26; i++)
    {
        if (res[i] > max)
        {
            max = res[i];
            idx = i + 65;
            isBoth = false;
        }
        else if (res[i] == max)
        {
            isBoth = true;
        }
    }

    if (isBoth)
        cout << "?" << endl;
    else
        cout << idx << endl;

    return 0;
}