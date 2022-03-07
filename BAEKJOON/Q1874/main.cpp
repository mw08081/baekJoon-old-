#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;
    bool isUsed[100001] {0};
    bool isPoped[10001] {0};
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
                cout << "+" << '\n';
            }
            i++;
        }
        while(i > input)
        {
            if(!isPoped[i])
            {
                s.pop();
                isPoped[i] = true;
                //cout << "-" << '\n';
                
                cout << "- ";
            }
            i--;
            cout << i << '\n';
        }
    }

    if(i != 1)
        cout << "NO" << '\n';



    return 0;
}