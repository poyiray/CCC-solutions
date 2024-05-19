#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int r, c;
char g[N][N];
int dist[N][N];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int bfs()
{
	queue<pair<int, int>> q;
	memset(dist, -1, sizeof dist);
	q.push({ 1,1 });
	dist[1][1] = 1;

	while (q.size())
	{
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (g[t.first][t.second] == '|' && i >= 2) continue;
			if (g[t.first][t.second] == '-' && i <= 1) continue;
			int a = t.first + dx[i], b = t.second + dy[i];
			if (a < 1 || a > r || b < 1 || b > c) continue;
			if (dist[a][b] >= 1) continue;
			if (g[a][b] == '*') continue;
			q.push({ a,b });
			dist[a][b] = dist[t.first][t.second] + 1;
			if (a == r && b == c) return dist[a][b];
		}
	}
	return dist[r][c];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int t; cin >> t;
	while (t--)
	{
		cin >> r >> c;
		for (int i = 1; i <= r; i++)
			cin >> g[i] + 1;
		cout << bfs() << endl;
	}

	return 0;
}