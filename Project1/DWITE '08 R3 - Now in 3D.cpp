#include <bits/stdc++.h>
using namespace std;

const int N = 6;
char g[N][N][N];
int dis[N][N][N];
int n;

int dx[] = { -1,1,0,0,0,0 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 0,0,0,0,-1,1 };

struct pos
{
	int x, y, z;
};
void bfs()
{
	memset(dis, -1, sizeof dis);
	queue<pos> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				if (g[i][j][k] == 'A')
				{
					q.push({ i,j,k });
					dis[i][j][k] = 0;
				}
	while (q.size())
	{
		auto u = q.front(); q.pop();
		for (int i = 0; i < 6; i++)
		{
			int x = u.x + dx[i], y = u.y + dy[i], z = u.z + dz[i];
			if (x < 0 || x >= n || y < 0 || y >= n || z < 0 || z >= n) continue;
			if (dis[x][y][z] >= 0) continue;
			if (g[x][y][z] == '#') continue;
			dis[x][y][z] = dis[u.x][u.y][u.z] + 1;
			q.push({ x,y,z });
			if (g[x][y][z] == 'B')
			{
				cout << dis[x][y][z] << endl;
				return;
			}
		}
	}
}

int main()
{
	int _ = 5;
	while (_--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> g[i][j];
		bfs();
	}
	return 0;
}