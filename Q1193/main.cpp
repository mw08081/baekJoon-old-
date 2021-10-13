//21.10.13 Q1193

#include <iostream>

using namespace std;;

int main()
{
	int dist;

	//계차수열의 데이터
	int a1 = 1;
	int an;

	int n = 1;

	//계차의 등차수열 데이터	-	a2값을 알아야지 등차수열의 데이터를 알 수 있으므로 따로 설정불가함 + a1 ~ a3 ...는 원래 있는 데이터임
	int a = 2;
	int d = 1;

	cin >> dist;

	an = a1;
	while (an < dist)
	{
		n++;
		an = a1 + (n - 1) * (2 * a + (n - 2) * d) / 2;
	}

	if (n % 2 != 0)
		cout << 1 + (an - dist) << "/" << n - (an - dist) << endl;
	else
		cout << n - (an - dist) << "/" << 1 + (an - dist) << endl;

	return 0;
}