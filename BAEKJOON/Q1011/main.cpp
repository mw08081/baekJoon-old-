#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    int st, end;
    int step, n = 1, remain, cnt;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> st >> end;
        step = end - st;
        cnt = 0;
        
        n = sqrt(step);

        remain = step - n * n;
        cnt += (n - 1) * 2 + 1;

         while(remain > 0)
        {
            remain -= n;
            cnt++;

            if(remain < n)
                n--;
        }
        cout << cnt << '\n';
    }
    return 0;
}