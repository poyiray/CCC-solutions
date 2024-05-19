#include <bits/stdc++.h> //并查集 模板
using namespace std;

unordered_map<string, string> fa;
unordered_map<string, bool> vis;
string find(string x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void merge(string x, string y) { fa[find(x)] = find(y); }

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n = 5;
	while (n--)
	{
		int m; cin >> m;
		vis.clear(), fa.clear();
		while (m--)
		{
			char opt;
			string x, y; cin >> opt >> x >> y;
			if (!vis[x]) fa[x] = x, vis[x] = 1;
			if (!vis[y]) fa[y] = y, vis[y] = 1;
			if (opt == 'p') merge(x, y);
			else
			{
				if (find(x) == find(y)) cout << "connected\n";
				else cout << "not connected\n";
			}
		}
	}
	return 0;
}