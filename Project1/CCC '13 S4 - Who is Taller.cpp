#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}

vector<vector<int>> g(1000010);
bool vis[1000010];

int s, e;
void bfs1()
{
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto val : g[u])
		{
			if (vis[val]) continue;
			vis[val] = true;
			q.push(val);
			if (val == e)
			{
				cout << "yes";
				exit(0);
			}
		}
	}
}
void bfs2()
{
	memset(vis, false, sizeof vis);
	queue<int> q;
	q.push(e);
	vis[e] = true;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto val : g[u])
		{
			if (vis[val]) continue;
			vis[val] = true;
			q.push(val);
			if (val == s)
			{
				cout << "no";
				exit(0);
			}
		}
	}
}

int main()
{
	int n = read(), m = read();
	while (m--)
	{
		int x = read(), y = read();
		g[x].push_back(y);
	}

	s = read(), e = read();
	bfs1();
	bfs2();
	cout << "unknown";

	return 0;
}