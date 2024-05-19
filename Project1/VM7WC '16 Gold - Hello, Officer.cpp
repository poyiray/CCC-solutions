#include <bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}
struct node
{
	int v, w;
	bool operator>(const node& n) const
	{
		return w > n.w;
	}
};
const int INF = 0x3f3f3f3f;
const int N = 2010;
vector<vector<node>> e(N);
priority_queue<node, vector<node>, greater<node>> q;
int dis[N], n, m, b, Q, t;
bool vis[N];

void dj()
{
	fill(dis, dis + n + 1, INF);
	q.push({ b, 0 });
	dis[b] = 0;
	while (q.size())
	{
		int u = q.top().v; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto val : e[u])
		{
			int w = val.w, v = val.v;
			if (vis[v]) continue;
			if (dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				q.push({ v, dis[v] });
			}
		}
	}
}

int main()
{
	n = rd(), m = rd(), b = rd(), Q = rd();

	while (m--)
	{
		int u = rd(), v = rd(), w = rd();
		e[u].push_back({ v,w });
		e[v].push_back({ u,w });
	}
	dj();
	while (Q--)
	{
		int t = rd();
		if (dis[t] == INF) cout << -1 << '\n';
		else cout << dis[t] << '\n';
	}

	return 0;
}