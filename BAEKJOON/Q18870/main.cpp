#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool CompFunc(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<pair<int, int> > sortedArr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr.at(i);
        sortedArr.at(i) = pair<int, int>(i, arr.at(i));
    }
    sort(sortedArr.begin(), sortedArr.end(), CompFunc);

    
    for (int i = 0; i < n; i++)
    {
        cout << sortedArr.at(i).first << " " << sortedArr.at(i).second << "       ";
    }
    cout << endl;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            /* code */
        }
        
    }
    
    
    

    return 0;
}