#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    string str;
    stack<char> ls;
    stack<char> rs;
    int csIdx, n;

    cin >> str >> n;
    cin.ignore();
    csIdx = str.length();
    for (int i = 0; i < str.length(); i++)
        ls.push(str[i]);

    while(n--)
    {
        string cmd;
        getline(cin, cmd);

        switch (cmd[0])                     //LDBP
        {
        case 'L' :
            if(!ls.empty())
            {
                rs.push(ls.top());
                ls.pop();
            }
            break;
        case 'D' :
            if(!rs.empty())
            {
                ls.push(rs.top());
                rs.pop();
            }
            break;
        case 'B' :
            if(!ls.empty())
                ls.pop();
            break;
        case 'P' :
            ls.push(cmd[2]);
            break;
        }
    }
    
    while(!ls.empty())
    {
        rs.push(ls.top());
        ls.pop();
    }
    while(!rs.empty())
    {
        cout << rs.top();
        rs.pop();
    }

    return 0;
}