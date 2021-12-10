#include <iostream>
using namespace std;

int main()
{
    double a, b, v;
    cin >> a >> b >> v;

    double res = (v - a) / (a - b) + 1;
    if (res > (int)res && res < (int)res + 1)
        res++;

    cout << (int)res << endl;


    //    tot += a;
    //    dayCnt++;
    //    while(tot < v){
    //        tot -= b;
    //
    //        tot += a;
    //        dayCnt++;
    //    }
    //
    //    cout << dayCnt << endl;


    return 0;
}
