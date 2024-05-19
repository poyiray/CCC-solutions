#include <bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}
struct node
{
	int v, w;
	bool operator>(const node& n) const 
	{
		return w > n.w;
	}
};
const int N = 110, INF = 0x3f3f3f3f;
int T, n, m, dis[N];
bool vis[N];
vector<vector<node>> e(N);

int cnt = 0, res = 0;
void prim(int x)
{
	fill(dis, dis + n + 1, INF);
	fill(vis, vis + n + 1, false);
	priority_queue<node, vector<node>, greater<node>> q;
	dis[x] = 0;
	q.push({ x, 0 });
	while (q.size())
	{
		if (cnt == n) break;
		int u = q.top().v; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		++cnt, res += dis[u];
		for (auto& val : e[u])
		{
			int v = val.v, w = val.w;
			if (w < dis[v] && !vis[v])
			{
				dis[v] = w;
				q.push({ v,w });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	T = rd();
	while (T--)
	{
		n = rd(), m = rd();
		while (m--)
		{
			int u = rd(), v = rd(), w = rd();
			e[u].push_back({ v,w });
			e[v].push_back({ u,w });
		}
		prim(1);
		if (cnt == n) cout << res << '\n';
		else cout << "Requires more conduits\n";
		e.clear(); e.resize(N);
		res = 0;
		cnt = 0;
	}

	return 0;
}