//21.10.13 Q2292

#include <iostream>

using namespace std;

int main()
{
	int dist = 0;
	
	int a;
	int aMasUno;
	int n = 1;
	int d = 6;

	cin >> dist;

	if (dist == 1)
		cout << 1 << endl;
	else
	{
		a = 1;
		aMasUno = a + n * d;
		while (aMasUno < dist)
		{
			n++;
			a = aMasUno;

			aMasUno = a + d * n;
		}

		cout << n + 1 << endl;
	}
	
	return 0;
}