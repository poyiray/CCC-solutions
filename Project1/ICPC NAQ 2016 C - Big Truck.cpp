#include <bits/stdc++.h>
using namespace std;

struct node
{
	int v, w;
	bool operator>(const node& n) const
	{
		return w > n.w;
	}
};
const int N = 110;
int dis[N], value[N], item[N], n, m;
vector<vector<node>> e(N);

void qwq()
{
	memset(dis, 0x3f, sizeof dis);
	priority_queue<node, vector<node>, greater<node>> q;
	q.push({ 1, 0 });
	dis[1] = 0, value[1] = item[1];
	while (q.size())
	{
		int u = q.top().v; q.pop();
		for (auto a : e[u])
		{
			int v = a.v, w = a.w;
			if (w + dis[u] < dis[v])
			{
				dis[v] = w + dis[u];
				value[v] = value[u] + item[v];
				q.push({ v, dis[v] });
			}
			else if (w + dis[u] == dis[v] && value[u] + item[v] > value[v])
				value[v] = value[u] + item[v];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> item[i];
	cin >> m;
	while (m--)
	{
		int u, v, w; cin >> u >> v >> w;
		e[u].push_back({ v,w });
		e[v].push_back({ u,w });
	}
	qwq();
	if (dis[n] > 100) cout << "impossible";
	else cout << dis[n] << " " << value[n];

	return 0;
}