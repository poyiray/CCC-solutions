#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
vector<int> e[N];
int mem[N], n, res;

int dfs(int u)
{
	if (mem[u]) return mem[u];
	if (u == n) return 1;
	for (auto& v : e[u]) mem[u] += dfs(v);
	return mem[u];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	int u, v;
	while (cin >> u >> v && u) e[u].push_back(v);
	cout << dfs(1);
	return 0;
}