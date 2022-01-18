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
void InsertData(vector<int> * arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        arr->push_back(tmp);
    }
}
vector<int> HeapSort(vector<int> * arr)
{
    vector<int> res {0};
    int len = arr->size() - 1;

    //MAXHEAPIFY
    for (int i = len / 2; i > 0; i--)
    {
        int p = i, c = p * 2;
        while(len >= c)
        {
            if(len >= c + 1 && arr->at(c + 1) > arr->at(c)) c++;
            if(arr->at(p) >= arr->at(c)) break;

            Swap(&arr->at(p), &arr->at(c));
            p = c;
            c = p * 2;
        }
    }

    //EXTRACT ELEMENT
    while(arr->size() > 1)
    {
        Swap(&arr->at(1), &arr->at(arr->size() - 1));
        res.push_back(arr->back());
        arr->pop_back();

        int p = 1, c = p * 2;
        while(arr->size() - 1 >= c)
        {
            if(arr->size() - 1 >= c + 1 && arr->at(c + 1) >= arr->at(c)) c++;
            if(arr->at(p) >= arr->at(c)) break;

            Swap(&arr->at(p), &arr->at(c));

            p = c;
            c = p * 2;
        }
    }
    for (int i = 1; i <= len / 2; i++)
        Swap(&res.at(i), &res.at(len - i + 1));

    return res;       
}

int GetAvg(vector<int> * arr)
{
    double tot = 0;
    for (int i = 1; i < arr->size(); i++)
        tot += arr->at(i);
    
    return floor(tot/(arr->size() - 1) + 0.5f);
}
int GetMid(vector<int> * arr)
{
    return arr->at((arr->size() - 1) / 2 + 1);
}
int GetMode(vector<int> * arr)
{
    if(arr->size() == 2)
        return arr->at(1);
    vector<int> vec;

    int tmp = 1, i, maxCnt = 0;
    for (i = 2; i < arr->size(); i++)
    {
        if(arr->at(i - 1) == arr->at(i))
            tmp++;
        else//if(arr[i - 1] != arr[i])
        {
            if(maxCnt < tmp)
            {
                vec.clear();
                maxCnt = tmp;
                vec.push_back(arr->at(i - 1));
            }
            else if(maxCnt == tmp)
                vec.push_back(arr->at(i - 1));
            tmp = 1;
        }
    }
    if(maxCnt < tmp)
    {
        vec.clear();
        maxCnt = tmp;
        vec.push_back(arr->at(i - 1));
    }
    else if(maxCnt == tmp)
        vec.push_back(arr->at(i - 1));
    
    if(vec.size() > 1)
        return vec.at(1);
    else
        return vec.at(0);

}
int GetScope(vector<int> * arr)
{
    return arr->at(arr->size() - 1) - arr->at(1);
}

int main()
{
    vector<int> arr {0};
    int n;
    cin >> n;

    InsertData(&arr, n);
    arr = HeapSort(&arr);

    cout << GetAvg(&arr) << '\n';
    cout << GetMid(&arr) << '\n';
    cout << GetMode(&arr) << '\n';
    cout << GetScope(&arr) << '\n';
    
    return 0;
}