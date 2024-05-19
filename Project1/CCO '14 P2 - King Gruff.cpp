#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
struct node
{
	int v, d, c;
	bool operator>(const node& n) const
	{
		return d > n.d;
	}
};
struct edge //td -- total dis
{
	int td, c;
	bool operator<(const edge& e) const
	{
		return td < e.td;
	}
};
const int N = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m, dis1[N], dis2[N], x, y, q, res[N];
pair<int, int>d[N];
vector<edge> a;
vector<vector<node>> e(N), e2(N);

void dj1()
{
	fill(dis1, dis1 + n + 1, INF);
	priority_queue<pair<int, int>> q;
	q.push({ 0, x });
	dis1[x] = 0;
	while (q.size())
	{
		int u = q.top().second; q.pop();
		for (auto& val : e[u])
		{
			int w = val.d, v = val.v;
			if (w + dis1[u] < dis1[v])
			{
				dis1[v] = dis1[u] + w;
				q.push({ -dis1[v], v });
			}
		}
	}
}

void dj2()
{
	fill(dis2, dis2 + n + 1, INF);
	priority_queue<pair<int, int>> q;
	q.push({ 0, y });
	dis2[y] = 0;
	while (q.size())
	{
		int u = q.top().second; q.pop();
		for (auto& val : e2[u])
		{
			int w = val.d, v = val.v;
			if (w + dis2[u] < dis2[v])
			{
				dis2[v] = dis2[u] + w;
				q.push({ -dis2[v], v });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> x >> y;
	for (int i = 1; i <= m; i++)
	{
		int u, v, d, c; cin >> u >> v >> d >> c;
		e[u].push_back({ v, d, c });
		e2[v].push_back({ u,d,c });
	}
	cin >> q;
	for (int i = 1; i <= q; i++) cin >> d[i].first, d[i].second = i;
	dj1(), dj2();

	a.push_back({ -1 });
	for (int i = 1; i <= n; i++)
	{
		for (auto& val : e[i])
		{
			int w = val.d, c = val.c, v = val.v;
			a.push_back({ dis1[i] + w + dis2[v],c });
		}
	}

	sort(a.begin() + 1, a.end());
	sort(d, d + q + 1);
	int t = 1, ans = 0;
	for (int i = 1; i <= q; i++)
	{
		res[d[i].second] = res[d[i - 1].second];
		while (a[t].td <= d[i].first && t <= m)
		{
			res[d[i].second] += a[t].c;
			t++;
		}
	}
	for (int i = 1; i <= q; i++) cout << res[i] << '\n';

	return 0;
}