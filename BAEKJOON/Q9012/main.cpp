#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> vpsChecker;
    string ps;
    int t;
    bool isVps;
    cin >> t;
    cin.ignore();

    while(t--)
    {
        cin >> ps;
        isVps = true;
        while(!vpsChecker.empty()) vpsChecker.pop();

        for (int i = 0; i < ps.length(); i++)
        {
            if(ps[i] == ')' && vpsChecker.empty())
            {
                cout << "NO" << '\n';
                isVps = false;
                break;
            }
            else if(ps[i] == ')')
                vpsChecker.pop();
            else                    //')'
                vpsChecker.push('(');
        }

        if(isVps)
            cout << (vpsChecker.empty() ? "YES" : "NO") << '\n';
    }


    return 0;
}