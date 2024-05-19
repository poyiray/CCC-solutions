#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, m, k, res, cnt;
vector<vector<int>> e(N);
char r[N];
int reachable[N];
bool vis[N];

void bfs(int x)
{
	cnt++;
	fill(vis, vis + n + 1, false);
	queue<int> q;
	q.push(x);
	reachable[x] = cnt;
	vis[x] = true;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto v : e[u])
		{
			if (vis[v])continue;
			if (r[v] != r[x]) continue;
			reachable[v] = cnt;
			vis[v] = true;
			q.push(v);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> k >> r + 1;
	while (m--)
	{
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
	{
		if (!reachable[i]) bfs(i);
	}

	while (k--)
	{
		int u, v; cin >> u >> v;
		if (reachable[u] == reachable[v]) res++;
	}
	cout << res;

	return 0;
}