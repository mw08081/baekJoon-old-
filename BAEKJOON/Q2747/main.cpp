#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 1, c = 0;
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    if(n == 1)
        c = 1;
    cout << c << '\n';
    return 0;
}