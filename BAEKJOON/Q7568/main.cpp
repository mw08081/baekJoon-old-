#include <iostream>
using namespace std;

int main()
{
    int n;  
    cin >> n;
    
    pair<int, int> people[50];
    for (int i = 0; i < n; i++)
        cin >> people[i].first >> people[i].second;
    
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        for (int j = 0; j < n; j++)
        {
            if(i == j)
                continue;

            if(people[i].first < people[j].first && people[i].second < people[j].second)
                cnt++;
        }
        cout << cnt << " ";
    }
    
    return 0;
}