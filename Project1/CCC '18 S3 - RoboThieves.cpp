#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

int x, y;
int n, m;
char g[N][N];
int st[N][N];
vector<pair<int, int>> rooms;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs()
{
	memset(st, -1, sizeof st);
	queue<pair<int, int>> q;
	q.push({ x, y });
	st[x][y] = 0;

	while (q.size())
	{
		auto t = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int a = t.first + dx[i], b = t.second + dy[i];
			while (g[a][b] == 'U' || g[a][b] == 'D' || g[a][b] == 'L' || g[a][b] == 'R')
			{
				if (st[a][b] != -1) break;
				st[a][b] = 1;
				if (g[a][b] == 'U') a -= 1;
				else if (g[a][b] == 'D') a += 1;
				else if (g[a][b] == 'L') b -= 1;
				else if (g[a][b] == 'R') b += 1;
			}
			if (a < 1 || a > n || b < 1 || b > m) continue;
			if (g[a][b] == 'W' || g[a][b] == 'C') continue;
			if (g[a][b] == 'X') continue;
			if (st[a][b] >= 0) continue;
			
			q.push({ a,b });
			st[a][b] = st[t.first][t.second] + 1;
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> g[i] + 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (g[i][j] == '.') rooms.push_back({ i,j });
			else if (g[i][j] == 'S') x = i, y = j;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (g[i][j] == 'C')
			{
				for (int k = 0; k < 4; k++)
				{
					int a = i + dx[k], b = j + dy[k];
					while (g[a][b] != 'W')
					{
						if (g[a][b] == '.') g[a][b] = 'X';
						else if (g[a][b] == 'S')
						{
							int cnt = rooms.size();
							while (cnt--) cout << -1 << endl;
							return 0;
						}
						a += dx[k], b += dy[k];
					}
				}
			}
		}
	}
	
	bfs();

	for (auto& val : rooms)
	{
		cout << st[val.first][val.second] << endl;
	}

	return 0;
}