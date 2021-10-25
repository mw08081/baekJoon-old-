//2581
#include <iostream>
using namespace std;

int main()
{
    int m, n;
    int s = 0, res = 0;

    cin >> m >> n;

    for (; n >= m; n--)
    {
        int i = 2;
        for (; i < n; i++)
            if (n % i == 0)
                break;

        if (i == n)
        {
            s += n;
            res = n;
        }
    }

    if (res == 0)
        cout << "-1" << endl;
    else
        cout << s << endl << res << endl;

    return 0;
}