#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 10;
inline int rd()
{
	int x = 0; char c = getchar();
	while (!isalnum(c)) c = getchar();
	while (isalnum(c)) x = x * 10 + c - '0', c = getchar();
	return x;
}

struct node
{
	int v, i;
};
vector<vector<node>> e(N);
string ans;
bool vis[N];
int n, m;

void dfs(int u, bool s) // u current node, s state
{
	for (auto& val : e[u])
	{
		int v = val.v, i = val.i;
		if (vis[v]) continue;
		vis[v] = true;
		if (s) ans[i] = 'R';
		else ans[i] = 'B';
		dfs(v, !s);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), m = rd();
	for (int i = 0; i < m; i++) ans += 'G';
	for(int i = 0; i < m; i++)
	{
		int u = rd(), v = rd();
		e[u].push_back({ v,i });
		e[v].push_back({ u,i });
	}
	for (int i = 1; i <= n; i++) if (!vis[i]) vis[i] = true, dfs(i, true);
	cout << ans;
	return 0;
}