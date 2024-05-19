#include <bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x = 0; char c = getchar();
	while (!isalnum(c)) c = getchar();
	while (isalnum(c)) x = x * 10 + c - '0', c = getchar();
	return x;
}
const int N = 260;
int club[N];
int t[N][N];
vector<set<int>> town_region(N);
vector<vector<int>> e(N);
int dis[N], dis2[N];
bool vis[N];
int n, m, l;

void connect(int i, int u, int v)
{
	if (!t[u][v]) t[u][v] = t[v][u] = i;
	else
	{
		e[i].push_back(t[u][v]);
		e[t[u][v]].push_back(i);
	}
	town_region[u].insert(i);
	town_region[v].insert(i);
}

void bfs(int x)
{
	memset(vis, 0, sizeof vis);
	memset(dis, 0, sizeof dis);
	queue<int> q;
	for (auto i : town_region[x]) q.push(i), vis[i] = 1;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto v : e[u])
		{
			if (vis[v]) continue;
			q.push(v);
			dis[v] = dis[u] + 1;
			vis[v] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	m = rd(), n = rd(), l = rd();
	for (int i = 0; i < l; i++) club[i] = rd();
	for (int i = 1; i <= m; i++)
	{
		int num = rd();
		vector<int> temp(num);
		for (int j = 0; j < num; j++) temp[j] = rd();
		for (int j = 0; j < num - 1; j++)
			connect(i, temp[j], temp[j + 1]);
		connect(i, temp.front(), temp.back());
	}
	for (int i = 0; i < l; i++)
	{
		bfs(club[i]);
		for (int i = 1; i <= n; i++) dis2[i] += dis[i];
	}
	int res = 0x3f3f3f3f, pos = 0;
	for (int i = 1; i <= m; i++) if (dis2[i] < res) res = dis2[i], pos = i; //m写成n 我这个猪头
	cout << res << '\n' << pos;
	return 0;
}