//2908

#include <iostream>
using namespace std;

int ReverseNum(string str)
{
    char tmp;

    tmp = str[2];
    str[2] = str[0];
    str[0] = tmp;

    return (str[0] - 48) * 100 + (str[1] - 48) * 10 + (str[2] - 48);
}

int main()
{
    int num1, num2;
    string str1, str2;

    cin >> str1 >> str2;

    num1 = ReverseNum(str1);
    num2 = ReverseNum(str2);

    if (num1 > num2)
        cout << num1 << endl;
    else if (num1 < num2)
        cout << num2 << endl;



    return 0;
}