#include <bits/stdc++.h>
//∂‡‘¥bfs
using namespace std;

const int N = 50;
char g[N][N];
int n, m;
int dis[N][N];
queue<pair<int, int>> flood;

int dx[] = { -1,0,1,0 }, dy[] = { 0,1,0,-1 };

void bfs1(int x, int y)
{
	queue<pair<int, int>> painter;
	painter.push({ x,y });
	dis[x][y] = 0;
	while (painter.size())
	{
		auto u = painter.front(); painter.pop();
		for (int i = 0; i < 4; i++)
		{
			int a = u.first + dx[i], b = u.second + dy[i];
			if (a < 0 || a >= n || b < 0 || b >= m) continue;
			if (g[a][b] == 'X') continue;
			if ((dis[u.first][u.second] + 1 >= dis[a][b]) && dis[a][b] != -1) continue;
			dis[a][b] = dis[u.first][u.second] + 1;
			painter.push({ a,b });
			if (g[a][b] == 'D')
			{
				cout << dis[a][b];
				return;
			}
		}
	}
	cout << "KAKTUS";
}

void bfs2()
{
	while (flood.size())
	{
		auto u = flood.front(); flood.pop();
		for (int i = 0; i < 4; i++)
		{
			int a = u.first + dx[i], b = u.second + dy[i];
			if (a < 0 || a >= n || b < 0 || b >= m) continue;
			if (g[a][b] == 'X' || g[a][b] == 'D') continue;
			if (dis[a][b] >= 0) continue;
			dis[a][b] = dis[u.first][u.second] + 1;
			flood.push({ a,b });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		fill(dis[i], dis[i] + m, -1);
	for (int i = 0; i < n; i++) cin >> g[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] == '*')
			{
				flood.push({ i,j });
				dis[i][j] = 0;
			}
	bfs2();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (g[i][j] == 'S')
			{
				bfs1(i, j);
				return 0;
			}

	return 0;
}