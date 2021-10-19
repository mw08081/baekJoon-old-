//2775
#include <iostream>
using namespace std;

int GetPeopleCnt(int k, int n)
{
    if (k == 0)
        return n;
    else if (n == 1)
        return GetPeopleCnt(k - 1, n);

    return GetPeopleCnt(k, n - 1) + GetPeopleCnt(k - 1, n);
}

int main()
{
    int T, k, n;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> k >> n;

        cout << GetPeopleCnt(k, n) << endl;
    }

    return 0;
}