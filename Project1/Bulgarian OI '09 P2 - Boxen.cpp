#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
vector<vector<int>> e(N);
int degree[N], n, res[2], ans;
bool vis[N];

void bfs(int s)
{
	queue<int> q;
	q.push(s);
	vis[s] = 1;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto v : e[u])
		{
			if (vis[v]) continue;
			vis[v] = 1;
		}
	}
}

int main()
{
	for (int k = 0; k < 2; k++)
	{
		cin >> n;
		priority_queue<pair<int, int>> q;
		for (int i = 1; i <= n; i++)
		{
			int u; cin >> u;
			e[u].push_back(i);
			degree[u]++;
		}
		for (int i = 1; i <= n; i++) q.push({ degree[i],i });
		while (q.size())
		{
			int u = q.top().second; q.pop();
			if (vis[u]) continue;
			ans++;
			bfs(u);
		}
		res[k] = ans;
		memset(vis, 0, sizeof vis);
		memset(degree, 0, sizeof degree);
		e.clear(), e.resize(N);
		ans = 0;
	}
	cout << res[0] << " " << res[1];
	return 0;
}