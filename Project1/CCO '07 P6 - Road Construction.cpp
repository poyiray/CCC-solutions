#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int low[N], degree[N], n, m, cnt;
vector<vector<int>> e(N);

void qwq(int u, int fa)
{
	low[u] = ++cnt;
	for (auto v : e[u])
	{
		if (v == fa) continue;
		if (!low[v]) qwq(v, u);
		low[u] = min(low[v], low[u]);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	while (m--)
	{
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	qwq(1, 1);
	for (int u = 1; u <= n; u++)
		for (auto v : e[u])
			if (low[u] != low[v]) degree[low[u]]++;
	int res = 0;
	for (int i = 1; i <= n; i++)
		if (degree[i] == 1) res++;
	cout << (res + 1) / 2;

	return 0;
}