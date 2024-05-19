#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;

		for (int i = pow(n, 0.5); i >= 1; i--)
		{
			if (n % i == 0)
			{
				cout << "Minimum perimeter is " << n / i * 2 + i * 2 << " with dimensions "
					<< i << " x " << n / i << endl;
				break;
			}
		}
	}

	return 0;
}