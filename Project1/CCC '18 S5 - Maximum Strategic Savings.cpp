#include <bits/stdc++.h>
using namespace std;

#define int long long

inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}

struct node
{
	int u, v, z;
	bool operator<(const node& n) const
	{
		return z > n.z;
	}
};
const int N = 1e5 + 10;
node a[N], b[N];
int fa[N], fb[N], n, m, p, q, maxn, res;

int find_a(int x) { return x == fa[x] ? x : fa[x] = find_a(fa[x]); };
int find_b(int x) { return x == fb[x] ? x : fb[x] = find_b(fb[x]); };

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), m = rd(), p = rd(), q = rd();
	//初始化并查集
	for (int i = 1; i <= m; i++) fa[i] = i;
	for (int i = 1; i <= n; i++) fb[i] = i;

	//纵向的连接
	for (int i = 1; i <= p; i++)
	{
		a[i] = { rd(),rd(),rd() };
		maxn += a[i].z * n;
	}

	//横向
	for (int i = 1; i <= q; i++)
	{
		b[i] = { rd(),rd(),rd() };
		maxn += b[i].z * m;
	}


	sort(a + 1, a + p + 1);
	sort(b + 1, b + q + 1);
	a[0].z = b[0].z = INT_MAX;
	while (m > 1 || n > 1)
	{
		if (a[p].z < b[q].z)
		{
			int fx = find_a(a[p].u), fy = find_a(a[p].v);
			if (fx != fy)
			{
				fa[fx] = fy;
				res += a[p].z * n;
				m--;
			}
			p--;
		}
		else
		{
			int fx = find_b(b[q].u), fy = find_b(b[q].v);
			if (fx != fy)
			{
				fb[fx] = fy;
				res += b[q].z * m;
				n--;
			}
			q--;
		}
	}

	cout << maxn - res;

	return 0;
}