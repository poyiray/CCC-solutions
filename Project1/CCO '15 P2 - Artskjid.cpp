#include <bits/stdc++.h>
using namespace std;

struct node { int u, d; };
const int N = 400;
int f[N], in[N], n, m;
vector<node> e[N];

int main()
{
	cin >> n >> m;
	while (m--)
	{
		int u, v, d; cin >> u >> v >> d;
		e[u].push_back({ v,d });
		in[v]++;
		
	}

	queue<int> q;
	q.push(0);
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto x : e[u])
		{
			int v = x.u, d = x.d;
			f[v] = max(f[v], f[u] + d);
			if (!--in[v]) q.push(v);
		}
	}
	cout << f[n - 1];

	return 0;
}