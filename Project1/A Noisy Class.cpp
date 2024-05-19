#include <bits/stdc++.h>
using namespace std;
//ÍØÆËÅÅĞò
const int N = 10010;
int n, m, indegree[N], res;
vector<vector<int>> e(N);
stack<int> s;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	while (m--)
	{
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		indegree[v]++;
	}

	for (int i = 1; i <= n; i++) if (!indegree[i]) s.push(i);
	while (s.size())
	{
		int u = s.top(); s.pop(); res++;
		for (auto& v : e[u]) if (!--indegree[v]) s.push(v);
	}
	if (res == n) cout << "Y";
	else cout << "N";
	return 0;
}