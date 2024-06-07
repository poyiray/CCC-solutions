#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m, x, y, dis[N], deg[N], len;
bool pho[N], vis[N];
vector<int> e[N];

void del()
{
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		deg[i] = e[i].size();
		if (e[i].size() == 1) q.push(i);
	}

	while (q.size())
	{
		int u = q.front(); q.pop();
		if (pho[u]) continue;
		vis[u] = 1;
		len--;
		for (auto v : e[u])
		{
			if (vis[v]) continue;
			if(--deg[v] == 1) q.push(v);
		}
	}
}

void dfs(int u, int fa)
{
	if (dis[u] > dis[x]) x = u;
	for (auto v : e[u])
	{
		if (v == fa || vis[v]) continue;
		dis[v] = dis[u] + 1;
		dfs(v, u);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m; len = n - 1;
	while (m--)
	{
		int x; cin >> x;
		pho[x] = 1;
	}

	for (int i = 1; i <= n - 1; i++)
	{
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	del();
	for (int i = 0; i < n; i++)
	{
		if (pho[i])
		{
			dfs(i, i);
			break;
		}
	}
	memset(dis, 0, sizeof dis);
	dfs(x, x);

	int maxn = 0;
	for (int i = 0; i < n; i++)
	{
		maxn = max(dis[i], maxn);
	}

	cout << maxn + (len - maxn) * 2;
	return 0;
}