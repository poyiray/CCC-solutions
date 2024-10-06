#include <bits/stdc++.h>
using namespace std;
char *p1, *p2, buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int rd()
{
	int x = 0; char ch = nc();
	while (ch < 48 || ch>57) ch = nc();
	while (ch >= 48 && ch <= 57) x = x * 10 + ch - 48, ch = nc();
	return x;
}

const int N = 3e5 + 10;
struct edge
{
	int u, v, w, f;
	bool operator<(const edge& e) const
	{
		if (w == e.w) return f < e.f;
		return w < e.w;
	}
}a[N];
int n, m, d, fa[N], res;

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), m = rd(), d = rd();
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= n - 1; i++)
	{
		int u = rd(), v = rd(), w = rd();
		a[i] = { u,v,w,0 };
	}
	for (int i = n; i <= m; i++)
	{
		int u = rd(), v = rd(), w = rd();
		a[i] = { u,v,w,1 };
	}
	sort(a + 1, a + 1 + m);

	int cnt = 0, idx;
	for (int i = 1; i <= m; i++)
	{
		int fx = find(a[i].u), fy = find(a[i].v);
		if (fx != fy)
		{
			res += a[i].f;
			if (++cnt == n - 1)
			{
				idx = i;
				break;
			}
			else fa[fx] = fy;
		}
	}
	if (!a[idx].f) { cout << res; return 0; }

	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int fx = find(a[i].u), fy = find(a[i].v);
		if (fx != fy)
		{
			if (a[i].w < a[idx].w || ((a[i].w == a[idx].w) && !a[i].f)) fa[fx] = fy;
			else if (!a[i].f && a[i].w <= d)
			{
				res--;
				break;
			}
		}
	}
	cout << res;

	return 0;
}