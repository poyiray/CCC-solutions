#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 10;
struct edge
{
	int d, x, y;
	bool operator<(const edge &n) const
	{
		return d < n.d;
	}
};
int x[N], y[N], n, cnt, pd[N], f[N], pa[N];
edge e[N * N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i <= n - 1; i++) for (int j = i + 1; j <= n; j++) e[++cnt] = { (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]), i, j };
	sort(e + 1, e + cnt + 1);
	
	for (int i = 1; i <= cnt; i++)
	{
		int d = e[i].d, u = e[i].x, v = e[i].y;
		
		if (d != pd[u])
		{
			pd[u] = d;
			pa[u] = f[u];
		}
		if (d != pd[v])
		{
			pd[v] = d;
			pa[v] = f[v];
		}

		if (!u) f[u] = max(f[u], pa[v]);
		else
		{
			f[u] = max(f[u], pa[v] + 1);
			f[v] = max(f[v], pa[u] + 1);
		}
	}
	cout << f[0] + 1;

	return 0;
}