#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<vector<int>> e(N);
int n, m, dfn[N], low[N], cnt, res;
bool cut[N];

void qwq(int u, int root)
{
	dfn[u] = low[u] = ++cnt;
	int child = 0;
	for (auto v : e[u])
	{
		if (v == root) continue;
		if (!dfn[v])
		{
			qwq(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u])
			{
				child++;
				if (root == u && child < 2) continue;
				if (!cut[u])
				{
					cut[u] = true;
					res++;
				}
			}
		}
		else
		{
			low[u] = min(low[u], dfn[v]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	while (m--)
	{
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		if (!dfn[i])
		{
			qwq(i, i);
			break;
		}
	}
	
	cout << res << '\n';
	for (int i = 1; i <= n; i++)
		if (cut[i]) cout << i << '\n';
	return 0;
}