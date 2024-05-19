#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
pair<int, int> fa[N][N];
int n, m, res;
char g[N][N];

auto find(pair<int, int> p)
{
	int x = p.first, y = p.second;
	if (fa[x][y] == p) return fa[x][y];
	return fa[x][y] = find(fa[x][y]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	res = n * m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			fa[i][j] = { i,j };
	for (int i = 1; i <= n; i++) cin >> g[i] + 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			pair<int, int> fx = find({ i,j }), fy;
			int x = i, y = j;
			if (g[i][j] == 'S') x++;
			else if (g[i][j] == 'N') x--;
			else if (g[i][j] == 'W') y--;
			else y++;
			if (x < 1 || x > n || y < 1 || y > m) continue;
			fy = find({ x,y });
			if (fx != fy)
			{
				fa[fx.first][fx.second] = fy;
				res--;
			}
		}
	}
	cout << res;
	return 0;
}