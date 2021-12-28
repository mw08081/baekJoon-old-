#include <iostream>
using namespace std;

int main()
{
    int n, i = 666, cnt = 0;
    cin >> n;

    while (n != cnt)
    {   
        int tmp = i, tmpCnt = 0;
        while (tmp >= 1)
        {
            if(tmp % 10 == 6)
                tmpCnt++;
            else
                tmpCnt = 0;

            tmp /= 10;
            if(tmpCnt == 3)
                break;
        }

        if(tmpCnt == 3)
            cnt++;
        i++;
    }
    cout << i - 1 << '\n';
   
    return 0;
}