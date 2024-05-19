#include <bits/stdc++.h>
using namespace std;

const int N = 40;
vector<vector<int>> e(N);
int layer[N];
int father[N];
int x, y;

void bfs1()
{
	queue<int> q;
	q.push('R' - 'A');
	layer['R' - 'A'] = 1;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto v : e[u])
		{
			if (layer[v] >= 1) continue;
			layer[v] = layer[u] + 1;
			q.push(v);
		}
	}
}

void bfs2()
{
	memset(father, -1, sizeof father);
	queue<int> q;
	q.push(x);
	father[x] = 100;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto v : e[u])
		{
			if (father[v] >= 0) continue;
			if (layer[u] == layer[v]) continue;
			father[v] = u;
			q.push(v);
			if (v == y)
			{
				stack<char> s;
				while (father[v] != 100)
				{
					s.push(v + 'A');
					v = father[v];
				}
				s.push(x + 'A');
				while (s.size())
				{
					cout << s.top();
					s.pop();
				}
				cout << '\n';
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int m, Q; cin >> m >> Q;
	for(int i = 0; i < m; i++)
	{
		string u, v; cin >> u >> v;
		e[u[0] - 'A'].push_back(v[0] - 'A');
		e[v[0] - 'A'].push_back(u[0] - 'A');
	}

	bfs1();
	while (Q--)
	{
		string u, v; cin >> u >> v;
		x = u[0] - 'A', y = v[0] - 'A';
		bfs2();
	}

	return 0;
}