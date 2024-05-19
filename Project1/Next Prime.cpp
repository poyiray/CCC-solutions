#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	if (n == 1)
	{
		cout << 2 << endl;
		return 0;
	}
	for (int i = n;; i++)
	{
		bool flag = false;
		for (int j = 2; j <= n / j; j++)
		{
			if (i % j == 0)
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << i << endl;
			break;
		}
	}

	return 0;
}