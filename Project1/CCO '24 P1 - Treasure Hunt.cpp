#include <bits/stdc++.h>
using namespace std;
char *p1, *p2, buf[10000000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int rd()
{
	int x = 0; char ch = nc();
	while (ch < 48 || ch>57) ch = nc();
	while (ch >= 48 && ch <= 57) x = x * 10 + ch - 48, ch = nc();
	return x;
}

struct node
{
	int u, w;
	bool operator<(const node &n) const
	{
		return w < n.w;
	}
};
const int N = 1e6 + 10;
int n, m, a[N];
vector<node> e[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), m = rd();
	for (int i = 1; i <= n; i++) a[i] = rd();

	while (m--)
	{
		int u = rd(), v = rd(), w = rd();
		e[u].push_back({ v,w });
		e[v].push_back({ u,w });
	}

	priority_queue<node> q;
	for (int i = 1; i <= n; i++) q.push({ i, a[i] });
	while (q.size())
	{
		auto[u, d] = q.top(); q.pop();
		if (d < a[u]) continue;
		for (auto &[v, w] : e[u])
		{
			if (a[u] - w > a[v])
			{
				a[v] = a[u] - w;
				q.push({ v, a[v] });
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << a[i] << '\n';

	return 0;
}