using namespace std;
#include <bits/stdc++.h>

struct node
{
	double x, y;
};
struct edge
{
	int u, v;
	double w;
	bool operator<(const edge& n) const
	{
		return w < n.w;
	}
};
const int N = 1010;
int fa[N], n, m, vis[N][N];
double res;
node cor[N];
vector<edge> e;
vector<pair<int, int>> ans;

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= n; i++)
	{
		double x, y; cin >> x >> y;
		cor[i] = { x,y };
	}
	cin >> m;
	while (m--)
	{
		int u, v; cin >> u >> v;
		vis[u][v] = 1;
		vis[v][u] = 1;
		e.push_back({ u,v,0 });
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (vis[i][j]) continue;
			e.push_back({ i,j, sqrt(pow((cor[i].x - cor[j].x),2) + pow((cor[i].y - cor[j].y),2)) });
		}
	}
	sort(e.begin(), e.end());
	for (auto& u : e)
	{
		int fx = find(u.u), fy = find(u.v);
		if (fx == fy) continue;
		fa[fx] = fy;
		res += u.w;
		if (!vis[u.v][u.u]) ans.push_back({ u.u, u.v });
	}
	cout << fixed << setprecision(2) << res << '\n';
	for (auto& v : ans) cout << v.first << " " << v.second << '\n';

	return 0;
}