#include <bits/stdc++.h>
using namespace std;

inline int rd()
{
	int x = 0; char c = getchar();
	while (c > '9' || c < '0') c = getchar();
	while (c <= '9' && c >= '0') x = x * 10 + c - '0', c = getchar();
	return x;
}

const int N = 1e5 + 10;
int in[N], n, m, f[N], res;
vector<int> e[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), m = rd();
	while (m--)
	{
		int u = rd(), v = rd();
		e[u].push_back(v);
		in[v]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
	{
		if (!in[i])q.push(i);
	}

	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto v : e[u])
		{
			f[v] = max(f[v], f[u] + 1);
			if (!--in[v]) q.push(v);
		}
	}
	for (int i = 1; i <= n; i++) res = max(res, f[i]);
	cout << res;
	return 0;
}