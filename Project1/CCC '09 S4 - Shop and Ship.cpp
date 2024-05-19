#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
inline int read()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}
const int INF = 0x3f3f3f3f;
const int N = 6000;
int s, n, m;
vector<vector<pair<int, int>>> g(N);
vector<pair<int, int>> cost;
vector<int> dis(N);

void dj()
{
	fill(dis.begin(), dis.end(), INF);
	priority_queue<pair<int, int>> q;
	q.push({ 0,s });
	dis[s] = 0;
	while (q.size())
	{
		int u = q.top().second; q.pop();
		for (int i = 0; i < g[u].size(); i++)
		{
			int v = g[u][i].first;
			int w = g[u][i].second;
			if (dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				q.push({ -dis[v],v });
			}
		}
	}
}

int main()
{
	n = read(), m = read();
	while (m--)
	{
		int u, v, w;
		u = read(); v = read(); w = read();
		g[u].push_back({ v,w });
		g[v].push_back({ u,w });
	}
	int k = read();
	while (k--)
	{
		int u, w;
		u = read(); w = read();
		cost.push_back({ u,w });
	}
	s = read();
	dj();
	int res = INF;
	for (auto val : cost)
	{
		int temp = dis[val.first] + val.second;
		if (temp < res) res = temp;
	}
	cout << res;

	return 0;
}