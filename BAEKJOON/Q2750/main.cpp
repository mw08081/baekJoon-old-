#include <iostream>
using namespace std;

void Swap(int * n1, int * n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void BubbleSort(int * arr, int n)
{
    for (int i = 0; i < n - 1; i++)       
        for (int j = 0; j < n - 1 - i; j++)
            if(arr[j + 1] < arr[j])
                Swap(&arr[j], &arr[j + 1]);
}

void SelectSort(int * arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int min = i;
            if(arr[min] > arr[j])
                Swap(&arr[min], &arr[j]);
        }
    }
}

void QuickSort(int * arr, int l, int r)
{
    if(l < r)
    {
        int p = 0;      //newPivot
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

void InsertionSort(int * arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int arr[1000] = {0};
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    //BubbleSort(arr, n);
    //SelectSort(arr, n);
    //QuickSort(arr, 0, n - 1);
    InsertionSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}