#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
unordered_map<string, vector<pair<string, int>>> m;
unordered_map<string, int> cost;

void solve()
{
	priority_queue<pair<int, string>> q;
	q.push({ 0,"YYZ" });
	cost["YYZ"] = 0;

	while (q.size())
	{
		string u = q.top().second; q.pop();
		for (int i = 0; i < m[u].size(); i++)
		{
			string v = m[u][i].first;
			if (cost[u] + m[u][i].second < cost[v])
			{
				cost[v] = cost[u] + m[u][i].second;
				q.push({ (cost[u] + m[u][i].second) * -1, v });
			}
		}
	}
}

int main()
{
	int _ = 5;
	while (_--)
	{
		int n; cin >> n;
		while (n--)
		{
			string u, v; cin >> u >> v;
			int w; cin >> w;
			cost[u] = cost[v] = INF;
			m[u].push_back({ v,w });
		}
		solve();
		cout << cost["SEA"] << endl;
		m.clear();
		cost.clear();
	}

	return 0;
}