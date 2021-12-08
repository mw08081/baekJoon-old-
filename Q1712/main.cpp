#include <iostream>
using namespace std;

int main()
{
	int staticPrice;
	int valuablePrice;
	int salePrice;

	cin >> staticPrice >> valuablePrice >> salePrice;

	if (valuablePrice >= salePrice)
		cout << -1 << endl;
	else
		cout << staticPrice / (salePrice - valuablePrice) + 1 << endl;

	return 0;
}