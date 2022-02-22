#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CompareFunc(const string &s1, const string &s2)
{
    if(s1.length() != s2.length())
        return s1.length() < s2.length();
    else
        return s1 < s2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /*
    int n;
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr.at(i);

    sort(arr.begin(), arr.end(), CompareFunc);

    for (vector<string>::iterator it = arr.begin(); it < arr.end(); it++)
    {
        if(it != arr.begin() && *it == *(it - 1))
            continue;
        cout << *it << '\n';
    }
    */

   string str1 = "a";
   string str2 = "b";

   cout << "res : " << (str1 < str2) << '\n';

    return 0;
}