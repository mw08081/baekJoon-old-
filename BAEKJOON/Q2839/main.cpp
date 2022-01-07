#include <iostream>
using namespace std;

int main()
{
    int tmp = 2000;
    int N;
    cin >> N;

    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
            if (i * 3 + j * 5 == N)
                if (tmp > i + j)
                    tmp = i + j;

    if (tmp == 2000)
        cout << -1 << endl;
    else
        cout << tmp << endl;
    return 0;
}
