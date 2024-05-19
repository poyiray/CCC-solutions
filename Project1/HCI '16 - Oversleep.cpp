#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int N = 1010;
string g[N];
int dis[N][N];
int n, m;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void bfs()
{
	memset(dis, -1, sizeof dis);
	queue<pair<int, int>> q;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if (g[i][j] == 's')
			{
				q.push({ i,j });
				dis[i][j] = 0;
			}
	while (q.size())
	{
		auto u = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int a = u.first + dx[i], b = u.second + dy[i];
			if (a < 1 || a > n || b < 1 || b > m) continue;
			if (dis[a][b] >= 0) continue;
			if (g[a][b] == 'X') continue;
			dis[a][b] = dis[u.first][u.second] + 1;
			q.push({ a,b });
			if (g[a][b] == 'e')
			{
				cout << dis[a][b] - 1;
				return;
			}
		}
	}
	cout << -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> g[i] + 1;
	bfs();

	return 0;
}