#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node 
{ 
	int v; ll c;
	bool operator>(const node &n) const
	{
		return c > n.c;
	}
};
const int N = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m; 
ll dis[N], val[N];
bool vis[N];
vector<node> e[N];

ll dj(int x)
{
	fill(dis + 1, dis + n + 1, INF);
	fill(vis + 1, vis + n + 1, 0);
	priority_queue<node, vector<node>, greater<node>> q;
	ll res = val[x];
	q.push({ x,0 });
	dis[x] = 0;
	while (q.size())
	{
		int u = q.top().v; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto &y  : e[u])
		{
			int v = y.v, c = y.c;
			if (!vis[v] && dis[u] + c < dis[v])
			{
				dis[v] = dis[u] + c;
				res = max(res, val[v] - dis[v]);
				q.push({ v,dis[v] });
			}
		}
	}
	return res;
}

int main()
{
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> val[i];

	while (m--)
	{
		int u, v; ll c; cin >> u >> v >> c;
		e[u].push_back({ v,c });
		e[v].push_back({ u,c });
	}

	for (int i = 1; i <= n; i++)
	{
		cout << dj(i) << '\n';
	}

	return 0;
}