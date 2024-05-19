#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	int a, b, cnt = 0, sum = 0;
	cin >> a >> b;
	for (int i = a; i <= b; i++)
	{
		for (int j = 2; j <= i / 2; j++)
		{
			if (i % j == 0)
			{
				cnt++;
			}
		}
		if (cnt == 2)
			sum++;
		cnt = 0;
	}

	cout << "The number of RSA numbers between " << a << " and " << b << " is " << sum;

	return 0;
}