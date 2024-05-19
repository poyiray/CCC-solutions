#include <bits/stdc++.h>
using namespace std;

int m, n;

bool isPrime(int x)
{
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0) return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> m;
	while (m--)
	{
		cin >> n;
		for (int i = 2; i <= n; i++)
		{
			if (isPrime(i) && isPrime(2 * n - i))
			{
				cout << i << " " << 2 * n - i << '\n';
				break;
			}
		}
	}

	return 0;
}