#include <iostream>
#include <cmath>
using namespace std;

void HanoiRC(int n, int from, int to, int mid)
{
    if(n == 1)
    {
        cout << from << " " << to << '\n';
    }
    else
    {
        
    }
}

int main()
{
    int n;
    cin >> n;

    cout << pow(2, n) - 1 << '\n';
    HanoiRC(n, 1, 3, 2);

    return 0;
}