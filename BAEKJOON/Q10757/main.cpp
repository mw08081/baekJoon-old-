//10757
#include <iostream>
using namespace std;

string Reverse(string str)
{
    for (int i = 0; i < str.length() / 2; i++)
    {
        char tmp;

        tmp = str[str.length() - 1 - i];
        str[str.length() - 1 - i] = str[i];
        str[i] = tmp;
    }

    return str;
}

int main()
{
    string a, b;

    cin >> a >> b;

    a = Reverse(a);
    b = Reverse(b);

    if (a.size() >= b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            char tmp;
            if(i >= b.size())
                tmp = a[i] - 48;
            else
                tmp = a[i] + b[i] - 96;

            a[i] = tmp % 10 + 48;
            if (tmp >= 10 && a[i + 1] == 0)
            {
                a.resize(a.size() + 1);
                a[i + 1] = (int)(tmp / 10) + 48;
            }
            else if (tmp >= 10)
                a[i + 1] += (int)(tmp / 10);
        }
        a = Reverse(a);
        cout << a << endl;
    }
    else
    {
        for (int i = 0; i < b.size(); i++)
        {
            char tmp;
            if (i >= a.size())
                tmp = b[i] - 48;
            else
                tmp = a[i] + b[i] - 96;

            b[i] = tmp % 10 + 48;
            if (tmp >= 10 && b[i + 1] == 0)
            {
                b.resize(b.size() + 1);
                b[i + 1] = (int)(tmp / 10) + 48;
            }
            else if (tmp >= 10)
                b[i + 1] += (int)(tmp / 10);
        }

        b = Reverse(b);
        cout << b << endl;
    }
    return 0;
}
