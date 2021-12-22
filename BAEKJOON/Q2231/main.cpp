#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, min = 1000001;
    cin >> n;

    int len = 0, tmp = n;
    while(tmp >= 1)
    {
        tmp /= 10;
        len++;
    }
    tmp = (n / pow(10, len - 1)) + (9 * (len - 1));

    for (int i = n - 1; i >= n - tmp; i--)
    {
        int sum = 0;
        int origin = i;
        while(origin >= 1)
        {
            sum += origin % 10;
            origin /= 10;
        }

        if(i + sum == n && i < min)
            min = i;

        sum = 0;
    }
    cout << (min == 1000001 ? 0 : min) << '\n';

    return 0;
}