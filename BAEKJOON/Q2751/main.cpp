#include <iostream>
#include <vector>
using namespace std;

/* summary - MergeSort */

int sorted[1000000];

void Merge(int * arr, int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = l;

    while(i <= mid && j <= r)       
    {
        if(arr[i] <= arr[j])
            sorted[k++] = arr[i++];
        else
            sorted[k++] = arr[j++];
    }

    if(i > mid)
        for (int t = j; t <= r; t++)
            sorted[k++] = arr[t];
    else
        for (int t = i; t <= mid; t++)
            sorted[k++] = arr[t];

    for (int t = l; t <= r; t++)
        arr[t] = sorted[t];
}

void MergeSort(int * arr, int l, int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;

        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, r);
        Merge(arr, l, mid, r);
    }
}

int main()
{
    int * arr = new int[1000000];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        arr[i] = tmp;
    }

    MergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}



/* summary - HeapSort Using Vector(Complete)

void Swap(int * n1, int * n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void InsertData(vector<int> * tree, int n)
{
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;

        tree->push_back(tmp);
    }
}
void MaxHeapify(vector<int> * tree)
{
    int len = tree->size() - 1;
    
    for (int i = len / 2; i > 0; i--)
    {
        int p = i, c = p * 2;                       //p = Parent, c = Child
        while(tree->size() - 1 >= p * 2)
        {
            if(tree->size() - 1>= c + 1 && tree->at(c + 1) > tree->at(c))  c++;     //자식이 i * 2 + 1까지 존재하는 경우
            if(tree->at(p) > tree->at(c))  break;                                   //부모가 자식보다 큰 경우(아래로는 더 이상 검사할 필요 없음)

            Swap(&tree->at(p), &tree->at(c));

            p = c;                                                                  //아래에 대해 검사하기 위한 절차
            c = p * 2;                                                              
        }
    }
}

void PrintData(vector<int> * tree)
{
    for (int i = 1; i < tree->size(); i++)
        cout << tree->at(i) << " ";
    cout << '\n';
}

void ExtractData(vector<int> * tree)
{
    vector<int> res;

    while(tree->size() > 1)
    {
        Swap(&tree->at(1), &tree->at(tree->size() - 1));
        res.push_back(tree->back());
        tree->pop_back();

        int p = 1, c = p * 2;
        while(tree->size() - 1 >= p * 2)
        {
            if(tree->size() - 1 >= c + 1 && tree->at(c + 1) > tree->at(c))  c++;
            if(tree->at(p) > tree->at(c)) break;

            Swap(&tree->at(p), &tree->at(c));

            p = c;
            c = p * 2;
        }
    }

    vector<int>::iterator it;
    for (it = res.end() - 1; it > res.begin() - 1; it--)
        cout << *it << " ";
}

int main()
{
    vector<int> tree{0};

    int n;
    cin >> n;

    InsertData(&tree, n);
    MaxHeapify(&tree);
    ExtractData(&tree);

    return 0;
}
*/

/* Summary - HeapSort Using Array(Not Complete)

#define MAX 1000000

struct MaxHeap {
    int * tree;
    int size;
};

void InsertData(MaxHeap* maxHeap)
{
    int value;
    cin >> value;

    maxHeap->size++;
    maxHeap->tree[maxHeap->size] = value;
}

void Swap(MaxHeap * maxHeap, int * n1, int * n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void MakeMaxHeap(MaxHeap * maxHeap)
{
    for (int i = maxHeap->size / 2; i > 0; i--)
    {
        int tmp = maxHeap->tree[i];
        int cur;
        if(i * 2 + 1 <= maxHeap->size)              //size / 2 노드가 자식이 두명일때
        {
            if(tmp < maxHeap->tree[i * 2] || tmp < maxHeap->tree[i * 2 + 1])        //부모노드가 자식노드보다 작은 경우
            {
                cur = maxHeap->tree[i * 2] > maxHeap->tree[i * 2 + 1] ? i * 2 : i * 2 + 1;
                Swap(maxHeap, &maxHeap->tree[i], &maxHeap->tree[cur]);
            }
            else continue;
        }
        else
        {
            if(tmp < maxHeap->tree[i * 2])
                Swap(maxHeap, &maxHeap->tree[i], &maxHeap->tree[i * 2]);
            else continue;
        }

        while(maxHeap->tree[cur] < maxHeap->tree[cur * 2] || maxHeap->tree[cur] < maxHeap->tree[cur * 2 + 1])
        {
            int tmp = maxHeap->tree[cur * 2] > maxHeap->tree[cur * 2 + 1] ? cur * 2 : cur * 2 + 1;
            Swap(maxHeap, &maxHeap->tree[cur], &maxHeap->tree[tmp]);

            cur = tmp;
        }
    }    
}

void HeapSort(MaxHeap * maxHeap, int n)
{
    for (int i = 1; i < n - 1; i++)
    {
        int max = maxHeap->tree[1];
        maxHeap->tree[1] = maxHeap->tree[maxHeap->size];
        maxHeap->tree[maxHeap->size] = max;
        
        maxHeap->size--;

        int cur = 1, c = cur * 2;
        while(cur * 2 <= maxHeap->size)
        {
            if(c + 1 <= maxHeap->size && maxHeap->tree[c] > maxHeap->tree[c + 1]) c++;

            if(maxHeap->tree[c] < maxHeap->tree[cur])
                break;

            Swap(maxHeap, &maxHeap->tree[cur], &maxHeap->tree[c]);
            cur = c;
        }
    }
}


int main()
{
    MaxHeap maxHeap = {new int [MAX], 0};
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        InsertData(&maxHeap);

    MakeMaxHeap(&maxHeap);

    

    HeapSort(&maxHeap, n);

    for (int i = 1; i < n + 1; i++)
        cout << maxHeap.tree[i] << '\n';
    
    

    return 0;
}
*/