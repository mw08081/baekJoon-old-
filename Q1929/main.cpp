//1929
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr;

    while (n <= m)
        arr.push_back(n++);

    //    for(vector<int>::iterator it = arr.begin(); it < arr.end(); it++)
    //        cout << *it << endl;

    for (int i = 2; i * i < m; i++)
    {
       // (j = i * i; (); j += i)
    }


    return 0;
}