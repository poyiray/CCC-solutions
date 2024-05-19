#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int d, n, q;
	cin >> n >> d;

	if (n == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	q = n / d;
	n = n - q * d;
	for (int i = n; i >= 2; i--)
		if (n % i == 0 && d % i == 0)
		{
			n /= i;
			d /= i;
			break;
		}

	if (q != 0)
		cout << q;

	if (n != 0)
	{
		if (q != 0)
			cout << " ";
		cout << n << "/" << d;
	}
		
	cout << endl;

	return 0;
}