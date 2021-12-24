#include <iostream>
using namespace std;

void HanoiRC(int n, int from, int to, int mid)
{
    if(n == 1)
    {
        cout << from << " " << to << '\n';
    }
    else
    {
        HanoiRC(n - 1, from, mid, to);
        cout << from << " " << to << '\n';
        HanoiRC(n - 1, mid, to, from);
    }
}

int main()
{
    int n;
    cin >> n;

    cout << (2 << (n - 1)) - 1 << '\n';
    HanoiRC(n, 1, 3, 2);

    return 0;
}