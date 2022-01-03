#include <iostream>
using namespace std;

void Swap(int * n1, int * n2)
{
    int tmp = *n1;
    *n1 = *n2;
    *n2 = tmp;
}

void BubbleSort(int * arr, int len)
{
    for (int i = 0; i < len - 1; i++)       
        for (int j = 0; j < len - 1 - i; j++)
            if(arr[j + 1] < arr[j])
                Swap(&arr[j], &arr[j + 1]);
}

int main()
{
    int arr[1000] = {0};
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    BubbleSort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';

    return 0;
}