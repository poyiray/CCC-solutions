#include <bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x = 0; char c = getchar();
	while (!isalnum(c)) c = getchar();
	while (isalnum(c)) x = x * 10 + c - '0', c = getchar();
	return x;
}
struct node
{
	int u, d;
	bool operator>(const node& n) const
	{
		return d > n.d;
	}
};
struct road
{
	int u, v, l, c;
	bool operator<(const road& r) const
	{
		return l != r.l ? l < r.l : c < r.c;
	}
};
const int N = 2010;
int fa[N], dis[N], n, m;
long long res;
road a[N];
vector<vector<node>> e(N);

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) { fa[find(x)] = find(y); }

bool dj(int x, int y, int d)
{
	memset(dis, 0x3f, sizeof dis);
	priority_queue<node, vector<node>, greater<node>> q;
	q.push({ x,0 });
	dis[x] = 0;
	while (q.size())
	{
		int u = q.top().u; q.pop();
		for (auto val : e[u])
		{
			int w = val.d, v = val.u;
			if (w + dis[u] < dis[v])
			{
				dis[v] = w + dis[u];
				q.push({ v, dis[v] });
			}
		}
	}
	return d < dis[y];
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), m = rd();
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int u = rd(), v = rd(), l = rd(), c = rd();
		a[i].u = u, a[i].v = v, a[i].l = l, a[i].c = c;
	}
	sort(a + 1, a + m + 1);
	for(int i = 1; i <= m; i++)
	{
		int u = a[i].u, v = a[i].v, c = a[i].c, l = a[i].l;
		if (find(u) ^ find(v))
		{
			res += a[i].c;
			e[u].push_back({ v,l });
			e[v].push_back({ u,l });
			merge(u, v);
		}
		else if (dj(u, v, l))
		{
			res += c;
			e[u].push_back({ v,l });
			e[v].push_back({ u,l });
		}
	}
	cout << res;

	return 0;
}