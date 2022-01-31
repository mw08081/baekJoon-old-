#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CompareFunc(string s1, string s2)
{
    if(s1.length() != s2.length)
        return s1.length() < s2.length();
    else
    {
        while()
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> arr;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string tmp;
        cin >> tmp;

        arr.push_back(tmp);
    }

    sort(arr.begin(), arr.end(), CompareFunc);

    cout << '\n';
    for (vector<string>::iterator it = arr.begin(); it < arr.end(); it++)
        cout << *it << '\n';

    return 0;
}