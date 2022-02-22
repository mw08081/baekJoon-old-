#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool SortCompare(pair<pair<int, int>, int> e1, pair<pair<int, int>, int> e2)
{
    return e1.first.second < e2.first.second;
}

bool SortReverseCompare(pair<pair<int, int>, int> e1, pair<pair<int, int>, int> e2)
{
    return e1.first.first < e2.first.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> arr(n);

    for (int  i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        arr.at(i).first = pair<int, int>(i, tmp);
        arr.at(i).second = 0;
    }

    sort(arr.begin(), arr.end(), SortCompare);

    arr.at(0).second = 0;
    for (int i = 1; i < n; i++)
    {
        int cnt = 0;
        
        while(arr.at(i).first.second == arr.at(i - 1 - cnt).first.second)
        {
            cnt++;

            if(i - 1 - cnt < 0)
                break;
        }
            
        arr.at(i).second = i - cnt;
    }
        
    sort(arr.begin(), arr.end(), SortReverseCompare);
    
    for (int i = 0; i < n; i++)
        cout << arr.at(i).second << " ";

    return 0;
}