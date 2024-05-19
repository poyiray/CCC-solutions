#include <bits/stdc++.h>
using namespace std;
int m, n;

int main()
{
	cin >> m;
	while (m--)
	{
		vector<int> sum;
		bool f = false;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			if (n % i == 0)
			{
				if (find(sum.begin(), sum.end(), i - n / i) != sum.end())
				{
					f = true;
					break;
				}
				else sum.push_back(n / i + i);
			}
		}
		cout << n << " is " << (f ? "nasty" : "not nasty") << '\n';
	}

	return 0;
}