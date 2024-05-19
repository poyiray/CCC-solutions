#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
char g[N][N];
int fa[N][N];
bool vis[N][N];
int n, m, cnt = 1, res, b;

void bfs(int xx, int yy)
{
	queue<pair<int, int>> q;
	q.push({ xx,yy });
	vis[xx][yy] = 1;
	fa[xx][yy] = cnt;
	while (q.size())
	{
		auto t = q.front(); q.pop();
		int x = t.first, y = t.second;
		if (g[x][y] == 'S') x++;
		else if (g[x][y] == 'W') y--;
		else if (g[x][y] == 'E') y++;
		else x--;
		if (x < 0 || x >= n || y < 0 || y >= m) continue;
		if (vis[x][y])
		{
			if (fa[x][y] != cnt && fa[x][y] != 0) b++;
			break;
		}
		fa[x][y] = cnt;
		vis[x][y] = 1;
		q.push({ x,y });
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> g[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!vis[i][j])
			{
				res++;
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << res - b;
	return 0;
}