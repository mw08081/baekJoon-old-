#include <iostream>
using namespace std;

int main()
{
    int num, div = 2;

    cin >> num;

    while (num > 1)
    {
        if (num % div == 0)
        {
            cout << div << endl;
            num /= div;
        }
        else
            div++;
    }

    return 0;
}