#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int r, c;
int dis[N][N];
char g[N][N];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int res;
void bfs(char s)
{
	memset(dis, -1, sizeof dis);
	queue<pair<int, int>> q;
	for(int i = 1; i <= 10; i++)
		for(int j = 1; j <= 10; j++)
			if (g[i][j] == s)
			{
				q.push({ i,j });
				dis[i][j] = 0;
			}
	while (q.size())
	{
		auto t = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int a = t.first + dx[i], b = t.second + dy[i];
			if (a < 1 || a > r || b < 1 || b > c) continue;
			if (dis[a][b] >= 0) continue;
			if (g[a][b] == '#') continue;
			dis[a][b] = dis[t.first][t.second] + 1;
			q.push({ a,b });
			if ((s == 'A' && g[a][b] == 'B') || (s == 'B' && g[a][b] == 'C') || (s == 'C' && g[a][b] == 'A'))
			{
				res += dis[a][b];
				return;
			}
		}
	}
}

int main()
{
	int n = 5;
	while (n--)
	{
		res = 0;
		cin >> r >> c;
		for (int i = 1; i <= r; i++) cin >> g[i] + 1;
		bfs('A'), bfs('B'), bfs('C');
		cout << res << endl;
	}


	return 0;
}