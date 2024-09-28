#include <bits/stdc++.h>
using namespace std;
inline __int128 rd()
{
	__int128 x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}


const int N = 100;
__int128 f[N][N], n, m, res, a[N];

void solve()
{
	memset(f, 0, sizeof f);
	for (int len = 1; len <= m; len++)
	{
		for (int l = 1, r = len; r <= m; r++, l++)
		{
			f[l][r] = max(2 * f[l + 1][r] + 2 * a[l], 2 * f[l][r - 1] + 2 * a[r]);
		}
	}
	res += f[1][m];
}

void print(__int128 x)
{
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int main()
{
	n = rd(), m = rd();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			a[j] = rd();
		}
		solve();
	}
	print(res);

	return 0;
}