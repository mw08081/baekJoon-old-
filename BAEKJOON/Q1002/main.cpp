#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int x1,y1,r1,x2,y2,r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;    

        double dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        
        if(dist == 0 && r1 == r2)
        {
            cout << -1 << endl;
        }
        else if(abs(r1 - r2) < dist && dist < r1 + r2)
            cout << 2 << '\n';
        else if(dist == r1 + r2 || dist == abs(r1 - r2))
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}