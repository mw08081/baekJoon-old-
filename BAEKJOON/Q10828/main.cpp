#include <iostream>
//#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int stack[10001] = {0};
    int n, tmp, idx = -1;
    string cmd;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> cmd;

        if(cmd[1] == 'u')
        {
            cin >> tmp;
            stack[++idx] = tmp;
        }
        else if(cmd[0] == 'p')
        {
            if(idx == -1)
                cout << "-1" << '\n';
            else
                cout << stack[idx--] << '\n';
        }
        else if(cmd[0] == 's')
            cout << idx + 1 <<'\n';
        else if(cmd[0] == 'e')
            cout << (idx == -1 ? "1" : "0") << '\n';
        else
        {
            if(idx == -1)
                cout << "-1" << '\n';
            else
                cout << stack[idx] << '\n';
        }

    }
    

    // stack<int> st;
    // int n, tmp;
    // string opt;

    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> opt;

    //     if(opt == "push")
    //     {
    //         cin >> tmp;
    //         st.push(tmp);
    //     }
    //     else if(opt == "pop")
    //     {
    //         if(st.empty())
    //             cout << "-1" << '\n';
    //         else
    //         {
    //             tmp = st.top();
    //             cout << tmp << '\n';
    //             st.pop();
    //         }
    //     }
    //     else if(opt == "size")
    //     {
    //         cout << st.size() << '\n';
    //     }
    //     else if(opt == "empty")   
    //     {
    //         if(st.empty())
    //             cout << "1" << '\n';
    //         else 
    //             cout << "0" << '\n';
    //     }
    //     else
    //     {
    //         if(st.empty())
    //             cout << "-1" << '\n';
    //         else
    //             cout << st.top() << '\n';
    //     }
    // }
}