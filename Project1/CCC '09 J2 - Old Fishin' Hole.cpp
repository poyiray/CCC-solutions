#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;

int a, b, c, lim, res;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> a >> b >> c >> lim;
	for (int i = 0; i <= lim / a; i++)
	{
		for (int j = 0; j <= (lim - i * a) / b; j++)
		{
			for (int k = 0; k <= (lim - j * b - i * a) / c; k ++)
			{
				if (i || j || k)
				{
					cout << i << " Brown Trout, " << j << " Northern Pike, " << k << " Yellow Pickerel\n";
					res++;
				}
			}
		}
	}
	cout << "Number of ways to catch fish: " << res;
	return 0;
}