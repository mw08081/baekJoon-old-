#define _USE_MATH_DEFINES 

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long double r;
    cin >> r;

    cout<<fixed;
    cout.precision(6);
    cout << M_PI * pow(r,2)<< "\n";
    cout << 2 * powl(r,2) << "\n";

    return 0;
}