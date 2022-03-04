#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    cin.ignore();

    string str;
    stack<char> res;

    int to = 0;
    for (int i = 0; i < t; i++)
    {
        getline(cin, str);
        str += ' ';
        
        for (int i = 0; i < str.length(); i++)
        {
            if(str[i] == ' ')
            {
                while(!res.empty())
                {
                    cout << res.top();
                    res.pop();
                }
                cout << " ";    
            }
            else
                res.push(str[i]);
        }
        cout << '\n';
    }

    return 0;
}