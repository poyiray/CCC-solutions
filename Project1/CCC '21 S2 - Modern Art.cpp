#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m, n; cin >> m >> n;
	int k; cin >> k;
	char c;
	int num;
	vector<int> row(m);
	vector<int> col(n);
	while (k--)
	{
		cin >> c >> num;
		if (c == 'R')
			row[num - 1]++;
		else
			col[num - 1]++;
	}
	int res = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((row[i] + col[j]) % 2 != 0)
				res++;
		}
	}
	cout << res;

	return 0;
}