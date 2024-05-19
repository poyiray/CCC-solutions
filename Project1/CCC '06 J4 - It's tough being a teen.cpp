#include <bits/stdc++.h>
using namespace std;

const int N = 8;
vector<vector<int>> g(N);
priority_queue<int, vector<int>, greater<int>> q;
vector<int> res;
int indegree[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	g[1].push_back(7), g[1].push_back(4);
	g[2].push_back(1);
	g[3].push_back(4), g[3].push_back(5);
	indegree[7] = 1, indegree[4] = 2, indegree[1] = 1, indegree[5] = 1;
	int u, v;
	while (cin >> u >> v)
	{
		if (!(u && v)) break;
		g[u].push_back(v);
		indegree[v]++;
	}
	for (int i = 1; i <= 7; i++)
		if (!indegree[i])
			q.push(i);

	while (q.size())
	{
		int u = q.top(); q.pop();
		res.push_back(u);
		for (auto& v : g[u])
		{
			if (!--indegree[v])
			{
				q.push(v);
			}
		}
	}

	if (res.size() != 7) cout << "Cannot complete these tasks. Going to bed.";
	else for (auto val : res) cout << val << " ";

	return 0;
}