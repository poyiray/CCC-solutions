#include <bits/stdc++.h>
using namespace std;

const int N = 1010, M = 1e9 + 7;
char g[N][N];
int f[N][N], n, m;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> g[i] + 1;
	f[n][m] = 1;
	for (int i = n; i >= 1; i--)
	{
		for (int j = m; j >= 1; j--)
		{
			if (g[i][j] == '#') continue;
			f[i][j] += (f[i][j + 1] + f[i + 1][j]) % M;
		}
	}
	cout << f[1][1];

	return 0;
}