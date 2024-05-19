#include <bits/stdc++.h>
using namespace std;
//查找树高 节省的时间 等于 总的使用时间(m) - 树高
const int N = 110;
int n, m, res;
string s[N];
unordered_map<string, vector<string>> e;
unordered_map<string, bool> vis;

int tree_high(string u, int h)
{
	vis[u] = 1;
	for (auto& v : e[u])
	{
		if (vis[v]) continue;
		res = max(tree_high(v, h + 1), res);
	}
	return h;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	while (n--)
	{
		cin >> m;
		for (int i = 0; i < m; i++) cin >> s[i];
		for (int i = 0; i < m; i += 2)
		{
			e[s[i]].push_back(s[i + 1]);
			e[s[i + 1]].push_back(s[i]);
		}
		tree_high(s[m - 1], 0);
		cout << m * 10 - res * 20 << '\n';
		vis.clear(), e.clear();
		res = 0;
	}

	return 0;
}