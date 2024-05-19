//找最短路径dfs不行
#include <iostream>
#include <queue>
using namespace std;
int g[10][10];
int e_x, e_y;
int x, y;
int dx[] = {  1, 1, 2,  2, -1, -1, -2, -2 };
int dy[] = { -2, 2, 1, -1, -2,  2,  1, -1 };

void bfs()
{
	memset(g, -1, sizeof g);
	queue<pair<int, int>> q;
	q.push({ x,y });
	g[x][y] = 0;

	while (q.size())
	{
		auto t = q.front(); q.pop();
		for (int i = 0; i < 8; i++)
		{
			int a = t.first + dx[i], b = t.second + dy[i];
			if (a < 1 || a > 8 || b < 1 || b > 8) continue;
			if (g[a][b] >= 0) continue;
			g[a][b] = g[t.first][t.second] + 1;
			q.push({ a,b });
			if (a == e_x && b == e_y)
			{
				cout << g[a][b] << endl;
				return;
			}
		}
	}
	cout << g[x][y];
}

int main() 
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> x >> y >> e_x >> e_y;
	bfs();
	
	return 0;
}