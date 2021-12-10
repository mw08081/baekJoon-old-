#include <iostream>
using namespace std;

int RecursiveCall(int n)
{
    if(n == 0)
        return 1;
    
    return n * RecursiveCall(n - 1);
}

int main()
{
    int n;
    cin >> n;

    cout << RecursiveCall(n) << '\n';

    return 0;
}