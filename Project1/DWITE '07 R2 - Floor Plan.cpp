#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> v;
char g[50][50];
int r, c, cnt;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void dfs(int x, int y)
{
	if (x < 0 || x >= r || y < 0 || y >= c) return;
	if (g[x][y] == '#') return;
	cnt++; g[x][y] = '#';
	for (int i = 0; i < 4; i++)
		dfs(x + dx[i], y + dy[i]);
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> g[i];
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (isalnum(g[i][j]))
			{
				cnt = 0;
				int num = g[i][j] - '0';
				dfs(i, j);
				v.push_back({ num, cnt });
			}
		}
	}

	sort(v.begin(), v.end());
	for (auto val : v) cout << val.second << endl;
	return 0;
}