#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

inline int rd()
{
	int x = 0;
	char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}


const int N = 1e5 + 10;
int m, n, x[N], y[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	m = rd();
	while (m--)
	{
		n = rd();
		for (int i = 1; i <= n; i++) x[i] = rd();
		for (int i = 1; i <= n; i++) y[i] = rd();

		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			int l = i - 1, r = n + 1, m;
			while (l + 1 != r)
			{
				m = (l + r) / 2;
				if (y[m] < x[i]) r = m;
				else l = m;
			}
			if (l <= i || y[l] < x[i]) continue;
			res = max(res, l - i);
		}
		cout << "The maximum distance is " << res << '\n';
	}

	return 0;
}