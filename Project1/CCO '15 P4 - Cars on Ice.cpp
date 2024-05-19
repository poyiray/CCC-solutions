#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

const int N = 3000, M = 1e7;
char g[N][N];
int n, m, cnt;
short in[M];
vector<int> e[M];

int d(int x, int y) { return y + m * x; }; // map 2d to 1d

void link(int i, int j)
{
	int vx = 0, vy = 0, x = i, y = j;
	if (g[i][j] == 'E') vy = 1;
	else if (g[i][j] == 'S') vx = 1;
	else if (g[i][j] == 'N') vx = -1;
	else if (g[i][j] == 'W') vy = -1;
	while (1)
	{
		x += vx, y += vy;
		if (x < 0 || x >= n || y < 0 || y >= m) break;
		if (g[x][y] != '.')
		{
			int v = d(i, j);
			e[d(x, y)].push_back(v);
			in[v]++;
		}
		if (g[i][j] == g[x][y]) break; // 如果遇到相同发现的车就停止搜索 不然会爆内存
	}
}

void topo()
{
	stack<int> s;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int v = d(i, j);
			if (!in[v] && g[i][j] != '.') s.push(v);
		}
	}
	while (s.size())
	{
		int u = s.top(); s.pop();
		int r = u / m;
		cout << '(' << r << ',' << u - r * m << ")\n";
		for (auto& v : e[u])
			if (!--in[v]) s.push(v);
	}
}

int main()
{
	//freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> g[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] != '.') link(i, j);
	topo();
	return 0;
}