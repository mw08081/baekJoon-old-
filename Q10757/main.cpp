
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
    string a, b, res;

    cin >> a >> b;

    a = Reverse(a);
    b = Reverse(b);

    if (a.length() > b.length())
        res.resize(a.length());
    else
        res.resize(b.length());


    for (int i = 0; res.size(); i++)
    {
        int tmp = (a[i] - 48) + (b[i] - 48);

        res[i] = (char)((tmp % 10) + 48);

        if (tmp / 10 != 0)
            res[i] += (tmp / 10);

    }

    res = Reverse(res);

    cout << res << endl;

    return 0;
}

/*
//10757_using cppSTL

#include <iostream>
#include <list>

using namespace std;

int main()
{
    string a,b;

    list<int> aList;
    list<int> bList;

    cin >> a >> b;

    for(int i = 0 ; i < a.length(); i++)
        aList.push_back(a[i] - 48);
    for(int i = 0 ; i < b.length(); i++)
        bList.push_back(b[i] - 48);

    list<int>::iterator it;
    for(it = aList.begin(); it != aList.end(); it++)
        cout << *it;
    cout << endl;
    for(it = bList.begin(); it != bList.end(); it++)
        cout << *it;
    cout << endl;

    if(aList.size() > bList.size())
    {
        int tmp = (int)aList.size() - (int)bList.size();

        for(int i = 0; i < tmp; i++)
            bList.push_front(0);
    }
    else if(aList.size() < bList.size())
    {
        int tmp = (int)bList.size() - (int)aList.size();

        for(int i = 0; i < tmp; i++)
            aList.push_front(0);
    }

    for(it = aList.begin(); it != aList.end(); it++)
        cout << *it;
    cout << endl;
    for(it = bList.begin(); it != bList.end(); it++)
        cout << *it;
    cout << endl;


    list<int>::iterator ait = aList.end();
    list<int>::iterator bit = bList.end();


    while(ait != aList.begin())
    {
        int tmp = (*ait + *bit);
        int tmpNum = tmp / 10;

        *ait = tmp % 10;

        ait--;
        bit--;
        if(tmpNum != 0)
            *ait += tmpNum;

    }

    for(ait = aList.begin(); ait != aList.end(); ait++)
        cout << *ait;
    cout << endl;



    return 0;
}
 */