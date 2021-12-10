#include <iostream>
using namespace std;

int Fibo(int a, int b, int i, int n)                //myIdea
{
    if(n == -1)
        return 0;
    else if(n == 0)
        return 1;
    else
    {
        if(i == n)
            return a + b;

        return Fibo(b, a + b, i + 1, n);
    }
}

int FiboModel2(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return FiboModel2(n - 2) + FiboModel2(n - 1);
}

int main()
{
    int a = 0, b = 1, c = 0;
    int n;
    cin >> n;

    cout << Fibo(0, 1, 1, n - 1);
    //cout << '\n' << FiboModel2(n) << '\n';

    return 0;
}