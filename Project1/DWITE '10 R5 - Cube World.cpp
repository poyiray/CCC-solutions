#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 30;
int g[N][N], n, m;
bool ntf[N][N]; //ntf -- need to fill
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };
int res;
void adjust(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x,y });
	ntf[x][y] = false;
	while (q.size())
	{
		auto t = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int a = t.first + dx[i], b = t.second + dy[i];
			if (a < 0 || a >= n || b < 0 || b >= m) continue;
			if (!ntf[a][b]) continue;
			ntf[a][b] = false;
			q.push({ a,b });
		}
	}
}

void check_height(int h)
{
	memset(ntf, false, sizeof ntf);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (g[i][j] < h) ntf[i][j] = true;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i != 0 && i != n - 1 && j != 0 && j != m - 1) continue;
			if (ntf[i][j]) adjust(i, j);
		}
	}
}

int main()
{	
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int _ = 5;
	while (_--)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> g[i][j];
		int height = -1;
		while (height++ <= 50)
		{
			check_height(height);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (ntf[i][j])
					{
						res++;
						g[i][j]++;
					}
				}
			}
		}
		cout << res << endl;
		res = 0;
	}

	return 0;
}