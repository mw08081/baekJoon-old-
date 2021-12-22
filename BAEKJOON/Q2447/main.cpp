#include <iostream>
#include <cmath>
using namespace std;

void RecursiveDraw(int n, int k, int i, int j)
{
    if(i == 0)        
        return;

    if(j == 0)
    {
        cout << "\n";
        RecursiveDraw(n, n / 3, i - 1, n);
        return;
    }

    if(k > 0)
    {
        if(((n * 2 / 3 >= i) && (n * 1 / 3 + 1 <= i) && (n * 2 / 3  >= j) && (n * 1 / 3 + 1 <= j)) ||
         (i % k >= (k / 3 + 1) && i % k <= (k / 3 * 2)) && (j % k >= (k / 3 + 1) && j % k <= (k / 3 * 2)))
        {
            cout << " ";
            RecursiveDraw(n, n / 3, i, j - 1); 
        }
        else
            RecursiveDraw(n, k / 3, i, j);    
    }
    else
    {
        cout << "*";
        RecursiveDraw(n, n / 3, i, j - 1);
    }
}

int main()
{
    int n;
    cin >> n;

    RecursiveDraw(n, n / 3, n, n);        

    return 0;
}