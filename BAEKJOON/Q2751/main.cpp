#include <iostream>
using namespace std;

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

        int cur = 1, child = cur * 2;
        while(cur * 2 <= maxHeap->size)
        {
            if(child + 1 <= maxHeap->size && maxHeap->tree[child] > maxHeap->tree[child + 1]) child++;

            if(maxHeap->tree[child] < maxHeap->tree[cur])
                break;

            Swap(maxHeap, &maxHeap->tree[cur], &maxHeap->tree[child]);
            cur = child;
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