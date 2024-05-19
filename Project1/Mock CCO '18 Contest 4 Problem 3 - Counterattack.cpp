#include <bits/stdc++.h>
using namespace std;
//极致快读
char buf[1 << 21], *p1 = buf, *p2 = buf;
inline char gc()
{
	if (p1 == p2)
	{
		//返回实际读到的字数
		p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin);
	}
	return *(p1++);
}
inline int rd()
{
	int x = 0; char ch = gc();
	while (ch<'0' || ch>'9') ch = gc();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = gc();
	return x;
}
struct node
{
	int u, w;
	bool operator>(const node& n) const
	{
		return w > n.w;
	}
};
const int N = 5 * 1e3 + 10, INF = 0x3f3f3f3f;
int dis1[N], dis2[N], n, m;
vector<vector<node>> e(N);
void dj1()
{
	fill(dis1, dis1 + n + 1, INF);
	priority_queue<node, vector<node>, greater<node>> q;
	q.push({ 1,0 });
	dis1[1] = 0;
	while (q.size())
	{
		int u = q.top().u; q.pop();
		for (auto val : e[u])
		{
			int v = val.u, w = val.w;
			if (w + dis1[u] < dis1[v])
			{
				dis1[v] = dis1[u] + w;
				q.push({ v,dis1[v] });
			}
		}
	}
}

void dj2()
{
	fill(dis2, dis2 + n + 1, INF);
	priority_queue<node, vector<node>, greater<node>> q;
	q.push({ n,0 });
	dis2[n] = 0;
	while (q.size())
	{
		int u = q.top().u; q.pop();
		for (auto val : e[u])
		{
			int v = val.u, w = val.w;
			if (w + dis2[u] < dis2[v])
			{
				dis2[v] = dis2[u] + w;
				q.push({ v,dis2[v] });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), m = rd();
	while (m--)
	{
		int u = rd(), v = rd(), w = rd();
		e[u].push_back({ v,w });
		e[v].push_back({ u,w });
	}
	dj1(), dj2();
	int res = INF;
	for (int i = 1; i <= n; i++)
	{
		for (auto val : e[i])
		{
			int v = val.u, w = val.w;
			int a = dis1[i] + w + dis2[v];
			if (a < res && a > dis1[n]) res = a;
		}
	}
	cout << res << '\n';
	return 0;
}