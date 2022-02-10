#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_LEN 100000
using namespace std;

vector<pair<int, string> > sorted(MAX_LEN);

void Merge(vector<pair<int, string> > * arr, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;

    while(i <= m && j <= r)
    {
        if(arr->at(i).first <= arr->at(j).first)
            sorted.at(k++) = arr->at(i++);
        else
            sorted.at(k++) = arr->at(j++);
    }

    if(i > m)
        for (int t = j; t <= r; t++)
            sorted.at(k++) = arr->at(t);
    else
        for (int t = i; t <= m; t++)
            sorted.at(k++) = arr->at(t);
        
    for (int t = l; t <= r; t++)
        arr->at(t) = sorted.at(t);      
}

void MergeSort(vector<pair<int, string> > * arr, int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        Merge(arr, l, m, r);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int, string> > arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr.at(i).first >> arr.at(i).second;

    MergeSort(&arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr.at(i).first << " " << arr.at(i).second << '\n';

    return 0;
}