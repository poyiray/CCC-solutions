#include <bits/stdc++.h>
using namespace std;
const int N = 8;
int n;
vector<vector<int>> e(N);
int dfs(int u, int sum = 1)
{
	if (!e[u].size()) return 2;
	for (auto v : e[u])
		sum *= dfs(v);
	return sum + 1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int u; cin >> u;
		e[u].push_back(i);
	}
	cout << dfs(n) - 1;
	return 0;
}