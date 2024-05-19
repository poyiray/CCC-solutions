#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 10010;
int n, m, d;
vector<int> city;
vector<vector<pair<int, int>>> g(N);
int dis[N];

void solve()
{
	priority_queue<pair<int, int>> q;
	q.push({ INF, 1 });
	dis[1] = INF;
	while (q.size())
	{
		int u = q.top().second; q.pop();
		for (int i = 0; i < g[u].size(); i++)
		{
			int w = g[u][i].second, v = g[u][i].first;
			if (min(w, dis[u]) > dis[v])
			{
				dis[v] = min(w, dis[u]);
				q.push({ dis[v], v });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> d;
	while (m--)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({ v,w });
		g[v].push_back({ u,w });
	}
	solve();
	while (d--)
	{
		int t; cin >> t;
		city.push_back(dis[t]);
	}

	sort(city.begin(), city.end());
	cout << city.front() << endl;

	return 0;
}