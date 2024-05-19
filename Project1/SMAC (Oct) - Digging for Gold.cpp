#include <bits/stdc++.h> //3d bfs
using namespace std;
struct node
{
	int x, y, z;
};
const int N = 15;
int n, res;
char g[N][N][N];
bool vis[N][N][N];
int dx[] = { 1,-1,0,0,0 }, dy[] = { 0,0,1,-1,0 }, dz[] = { 0,0,0,0,1 };

void bfs()
{
	queue<node> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (g[0][i][j] != 'X') q.push({ i,j,0 }), vis[0][i][j] = 1;
	while (q.size())
	{
		node u = q.front(); q.pop();
		for (int i = 0; i < 5; i++)
		{
			int a = u.x + dx[i], b = u.y + dy[i], c = u.z + dz[i];
			if (a >= n || a < 0 || b >= n || b < 0 || c >= n) continue;
			if (vis[c][a][b]) continue;
			if (g[c][a][b] == 'X') continue;
			if (g[c][a][b] == '*') ++res;
			q.push({ a,b,c });
			vis[c][a][b] = 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> g[i][j];
	bfs();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (g[0][i][j] == '*') res++;
	cout << res;
	return 0;
}