#include <bits/stdc++.h>
using namespace std;
const int N = 600;
vector<vector<int>> e(N);
int a[N], n, m, dis[N];
bool vis[N];

void bfs()
{
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto v : e[u])
		{
			if (vis[v]) continue;
			dis[v] = dis[u] + 1;
			q.push(v);
			vis[v] = 1;
			if (v == n) return;
		}
	}
}

int main()
{
	cin >> m >> n; cin.get();
	while (m--)
	{
		int cnt = 0;
		scanf("%d", &a[++cnt]);
		char c = getchar();
		while (c == ' ')
		{
			scanf("%d", &a[++cnt]);
			c = getchar();
		}

		for (int i = 1; i <= cnt; i++)
			for (int j = i + 1; j <= cnt; j++) e[a[i]].push_back(a[j]);
	}
	bfs();
	if (!vis[n]) cout << "NO";
	else cout << dis[n] - 1;
	return 0;
}