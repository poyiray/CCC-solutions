#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
int f[N][N], n, res;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> f[i][j];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!f[i][j]) continue;
			f[i][j] = min({ f[i - 1][j - 1], f[i][j - 1], f[i - 1][j] }) + 1;
		}
	}

	int maxn = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			maxn = max(maxn, f[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (f[i][j] == maxn) res++;
		}
	}
	cout << res * maxn;
}