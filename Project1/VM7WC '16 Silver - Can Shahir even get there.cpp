#include <bits/stdc++.h> //bfs Ä£°å
using namespace std;

const int N = 2010;
int vis[N], n, m, a, b;
vector<int> e[N];

bool qwq()
{
	queue<int> q;
	q.push(a);
	vis[a] = 1;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto v : e[u])
		{
			if (vis[v]) continue;
			vis[v] = 1; q.push(v);
			if (v == b) return true;
		}
	}
	return false;
}

int main()
{
	cin >> n >> m >> a >> b;
	while (m--)
	{
		int u, v; cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cout << ((qwq() || a == b) ? "GO SHAHIR!" : "NO SHAHIR!");

	return 0;
}