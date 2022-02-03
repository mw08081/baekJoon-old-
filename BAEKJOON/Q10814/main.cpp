#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_LEN 100000
using namespace std;

vector<pair<int, string>> sorted(MAX_LEN);

int main()
{
    int n;
    cin >> n;
    vector<pair<int, string>> arr(n);

    for (int i = 0; i < n; i++)
    {
        int ageTmp;
        string nameTmp;

        cin >> ageTmp >> nameTmp;

        arr.at(i) = pair<int, string>(ageTmp, nameTmp);
    }

    for (int i = 0; i < n; i++)
        cout << arr.at(i).first << " " << arr.at(i).second << '\n';

    return 0;
}