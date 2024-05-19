#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int dfn[N], n, m, cnt;
vector<int> e[N];

void dfs(int u)
{
	dfn[u] = ++cnt;
	for (auto v : e[u])
	{
		if (dfn[v])
		{
			if(dfn[u] - dfn[v] + 1 >= 6) { cout << "YES"; exit(0); }
			continue;
		}
		dfs(v);
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
	dfs(1);
	cout << "NO";
	return 0;
}