#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;
    string res;
    bool isUsed[100002] {0};
    bool isPoped[100002] {0};
    int n, i = 1, input;
    cin >> n;

    while(n--)
    {
        cin >> input;

        while(i <= input)
        {
            if(!isUsed[i])
            {
                isUsed[i] = true;
                s.push(i);
                res += "+\n";
            }
            i++;
        }
        while(i > input)
        {
            if(!isPoped[i])
            {
                s.pop();
                isPoped[i] = true;
                res += "-\n";
            }
            i--;
        }
    }

    if(!s.empty())
        cout << "NO" << '\n';
    else
        cout << res;

    return 0;
}