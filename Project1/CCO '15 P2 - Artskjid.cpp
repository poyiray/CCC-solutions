#include <bits/stdc++.h>
using namespace std;

#define int long long
struct node
{
	int v, w;
};
const int N = 2 << 19, M = 20;
int f[N][M], n, m, res;
vector<node> e[M];

signed main()
{
	memset(f, -1, sizeof f);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		e[u].push_back({ v,w });
	}
	f[(1 << n) - 1][n - 1] = 0;
	for (int i = (1 << n) - 1; i >= 0; i--)
	{
		for (int u = 0; u < n; u++)
		{
			for (auto[v, w] : e[u])
			{
				if (!(i >> v & 1) && f[i | 1 << v][v] != -1)
				{
					f[i][u] = max(f[i][u], f[i | 1 << v][v] + w);
				}
			}
		}
	}
	for (int i = 0; i < (1 << n); i++) res = max(res, f[i][0]);
	cout << res;

	return 0;
}