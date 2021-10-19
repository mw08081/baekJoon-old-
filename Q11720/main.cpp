// 11720
 
#include <iostream>
using namespace std;


int main()
{
    int cnt, sum = 0;
    string str;

    cin >> cnt;
    cin >> str;

    for (int i = 0; i < cnt; i++)
        sum += (str[i] - 48);

    cout << sum << endl;

    return 0;
}