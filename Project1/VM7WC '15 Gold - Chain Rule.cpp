#include <bits/stdc++.h>
using namespace std;
inline int read()
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
const int N = 100010;
int n, m;
vector<vector<node>> e(N);
int dis1[N], dis2[N];
bool vis[N];

void dj1()
{
	priority_queue<node, vector<node>, greater<node>> q;
	fill(dis1, dis1 + n + 1, INF);
	q.push({ 0,0 });
	dis1[0] = 0;
	while (q.size())
	{
		int u = q.top().v; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto val : e[u])
		{
			int w = val.w, v = val.v;
			if (vis[v]) continue;
			if (w + dis1[u] < dis1[v])
			{
				dis1[v] = w + dis1[u];
				q.push({ v, dis1[v] });
			}
		}
	}
}

void dj2()
{
	priority_queue<node, vector<node>, greater<node>> q;
	fill(vis, vis + n + 1, false);
	fill(dis2, dis2 + n + 1, INF);
	q.push({ n - 1,0 });
	dis2[n - 1] = 0;
	while (q.size())
	{
		int u = q.top().v; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (auto val : e[u])
		{
			int w = val.w, v = val.v;
			if (vis[v]) continue;
			if (w + dis2[u] < dis2[v])
			{
				dis2[v] = w + dis2[u];
				q.push({ v, dis2[v] });
			}
		}
	}
}

int main()
{
	n = read(), m = read();
	while (m--)
	{
		int u = read(), v = read(), w = read();
		e[u].push_back({ v,w });
		e[v].push_back({ u,w });
	}
	dj1();
	dj2();
	int res = 0;
	for (int i = 0; i < n; i++) 
		if (dis1[i] + dis2[i] > res) 
			res = dis1[i] + dis2[i];
	cout << res;
	return 0;
}