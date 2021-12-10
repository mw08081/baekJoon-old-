#include <iostream>
using namespace std;

int main()
{
    int num, T, cnt = 0;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> num;

        int j = 2;
        for (; j < num; j++)
            if (num % j == 0)
                break;

        if (j == num)
            cnt++;
    }

    cout << cnt << endl;

    return 0;
}