#include <bits/stdc++.h>
using namespace std;

inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}

const int INF = 0x3f3f3f3f;
const int N = 2010;
vector<vector<pair<int, int>>> e(N);
int shop[N], dis[N];
bool vis[N];
int t, n, m, g;

void dj()
{
	fill(dis, dis + n + 1, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0,0 });
	dis[0] = 0;
	while (q.size())
	{
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto val : e[u])
		{
			int w = val.second, v = val.first;
			if (dis[u] + w > t) continue;
			if (dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				q.push({ dis[v], v });
			}
		}
	}
}

int main()
{
	t = rd(), n = rd(), m = rd(), g = rd();
	for (int i = 0; i < g; i++) shop[i] = rd();
	int u, v, w;
	while (m--)
	{
		u = rd(), v = rd(), w = rd();
		e[u].push_back({ v,w });
	}
	dj();
	int res = 0;
	for (int i = 0; i < g; i++) if (dis[shop[i]] < INF) res++;
	printf("%d", res);
	return 0;
}