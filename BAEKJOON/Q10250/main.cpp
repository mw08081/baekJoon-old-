
//10250

#include <iostream>
using namespace std;

int main()
{
    int T;
    int h, w, n;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> h >> w >> n;

        if (n % h == 0)
            cout << h * 100 + (n / h) << endl;
        else
            cout << (n % h) * 100 + ((n / h) + 1) << endl;
    }

    return 0;
}