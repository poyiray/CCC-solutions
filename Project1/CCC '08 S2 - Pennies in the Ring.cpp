#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	while (cin >> n && n)
	{
		int res = 0;
		for (int i = 1; i < n; i++)
			res += sqrt(n * n - i * i);
		res *= 4, res++, res += 4 * n;
		cout << res << '\n';
	}

	return 0;
}