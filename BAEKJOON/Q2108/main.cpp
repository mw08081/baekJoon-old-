#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void Swap(int * n1, int * n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void QuickSort(int * arr, int l, int r)
{
    if (l < r)
    {
        int p = 0;

        for (int i = 0; i < r; i++)
        {
            if(arr[i] < arr[r])
            {
                Swap(&arr[p], &arr[i]);
                p++;
            }
        }
        Swap(&arr[p], &arr[r]);

        QuickSort(arr, l, p - 1);
        QuickSort(arr, p + 1, r);
    }
}

int GetAvg(int * arr, int n)
{
    double tot = 0;
    for (int i = 0; i < n; i++)
        tot += arr[i];
    
    return floor(tot/n + 0.5f);
}

int GetMid(int * arr, int n)
{
    return arr[n / 2];
}

int GetMode(int * arr, int n)
{
    if(n == 1)
        return arr[0];

    vector<int> vec;

    int tmp = 1, i, maxMode = -4000001;
    for (i = 1; i < n; i++)
    {
        if(arr[i - 1] == arr[i])
            tmp++;
        else//if(arr[i - 1] != arr[i])
        {
            if(maxMode < tmp)
            {
                vec.clear();
                maxMode = tmp;
                vec.push_back(arr[i - 1]);
            }
            else if(maxMode == tmp)
            {
                vec.push_back(arr[i - 1]);
            }
            tmp = 1;
        }
    }
    if(maxMode < tmp)
    {
        vec.clear();
        maxMode = tmp;
        vec.push_back(arr[i - 1]);
    }
    else if(maxMode == tmp)
    {
        vec.push_back(arr[i - 1]);
    }
    
    // cout << "maxMode " << maxMode << endl << "list ";
    // for (int i = 0; i < vec.size(); i++)
    //     cout << vec.at(i) << " ";
    // cout << endl;
    
    if(vec.size() > 2)
        return vec.at(1);
    else if(vec.size() == 2)
        return vec.at(0);
    else
        return vec.at(0);

}

int GetScope(int * arr, int n)
{
    return arr[n - 1] - arr[0];
}

int main()
{
    int arr[500000];
    

    int n;
    cin >> n;
    for (int  i = 0; i < n; i++)
        cin >> arr[i];
    
    QuickSort(arr, 0, n - 1);

    //cout << GetAvg(arr, n) << '\n';
    //cout << GetMid(arr, n) << '\n';
    cout << GetMode(arr, n) << '\n';
    //cout << GetScope(arr, n) << '\n';
    
    
    

    return 0;
}