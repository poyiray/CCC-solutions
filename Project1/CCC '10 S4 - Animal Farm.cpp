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
struct node
{
	int group, w;
};
struct PEN
{
	int v, w;
	bool operator>(const PEN& p) const
	{
		return w > p.w;
	}
};
const int N = 1010;
node e[N][N];
vector<vector<PEN>> pen(N);
int n, m;
bool used[N][N], vis[N];
int dis[N];

void connect(int u, int v, int w, int i)
{
	if (used[u][v])
	{
		pen[i].push_back({ e[u][v].group, e[u][v].w });
		pen[e[u][v].group].push_back({ i, pen[i].back().w });
		used[u][v] = used[v][u] = false;
	}
	else
	{
		e[u][v] = e[v][u] = { i,w };
		used[u][v] = used[v][u] = true;
	}
}

int qwq(int s, int& cnt)
{
	memset(dis, 0x3f, sizeof dis);
	memset(vis, false, sizeof vis);
	int res = 0;
	priority_queue<PEN, vector<PEN>, greater<PEN>> q;
	q.push({ s, 0 });
	dis[s] = 0;
	while (q.size())
	{
		if (cnt >= n) break;
		int u = q.top().v, w = q.top().w; q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		res += w;
		cnt++;
		for (auto val : pen[u])
		{
			int v = val.v, w = val.w;
			if (w < dis[v])
			{
				dis[v] = w;
				q.push({ v, w });
			}
		}
	}
	return res;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++)
	{
		vector<int> temp, w;
		m = read();
		for (int i = 0; i < m; i++)
			temp.push_back(read());
		for (int i = 0; i < m; i++)
			w.push_back(read());
		for (int j = 0; j < m - 1; j++)
			connect(temp[j], temp[j + 1], w[j], i);
		connect(temp.back(), temp.front(), w[m - 1], i);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (used[i][j] && e[i][j].group)
			{
				pen[0].push_back({ e[i][j].group, e[i][j].w });
				used[j][i] = used[i][j] = false;
			}
		}
	}
	int cnt1 = 0, cnt2 = 0;
	int res1 = qwq(1, cnt1); n++;
	int res2 = qwq(0, cnt2);
	if (cnt1 != n - 1) cout << res2;
	else cout << min(res1, res2);

	return 0;
}