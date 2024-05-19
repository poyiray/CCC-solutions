#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 2010;
struct node
{
	int v, w, h;
	bool operator>(const node& n) const
	{
		return w > n.w;
	}
};

int k, n, m, a, b;
vector<vector<node>> g(N);
int dis[N][210];
bool vis[N][210];

int dj()
{
	priority_queue<node, vector<node>, greater<node>> q;
	q.push({ a,0,0 });
	dis[a][0] = 0;
	while (q.size())
	{
		auto t = q.top(); q.pop();
		int u = t.v;
		if (vis[u][t.h]) continue;
		vis[u][t.h] = true;
		if (u == b)
			return dis[u][t.h];
		for (auto val : g[u])
		{
			int v = val.v;
			if (t.h + val.h >= k) continue;
			if (dis[u][t.h] + val.w < dis[v][val.h + t.h])
			{
				dis[v][val.h + t.h] = dis[u][t.h] + val.w;
				q.push({ v, dis[v][val.h + t.h] , t.h + val.h });
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> k >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		fill(dis[i], dis[i] + k + 1, INF);
	}
	while (m--)
	{
		int u, v, w, h; cin >> u >> v >> w >> h;
		g[u].push_back({ v,w,h });
		g[v].push_back({ u,w,h });
	}
	cin >> a >> b;
	int res = dj();
	cout << res;
	return 0;
}