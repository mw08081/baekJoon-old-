#include <iostream>
using namespace std;

int main()
{
	int length;
	cin >> length;

	string strs[100];
	for (int i = 0; i < length; i++)
		cin >> strs[i];

	int stack = 1;
	bool isBreak = false;
	int cnt = 0;

	for (int x = 0; x < length; x++)
	{
		stack = 1;
		isBreak = false;
		for (int i = 1; i < strs[x].length(); i++)
		{
			if (strs[x][i] == strs[x][i - 1])
			{
				stack++;
				continue;
			}
			else
				stack = 1;

			for (int j = 0; j < i - stack; j++)
				if (strs[x][i] == strs[x][j])
					isBreak = true;

			if (isBreak)
				break;
		}
		if (!isBreak)
			cnt++;
	}
	
	cout << cnt << endl;
	
	return 0;
}