#include <bits/stdc++.h>
using namespace std;

const int N = 30010;
int d[4][2] ={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
char g[400][90];
vector<pair<int, int>> loc[4];
char mov[N];
int r, c, m;
void init()
{
	loc[0].push_back({ 0,0 }); loc[1].push_back({ 0,0 });
	loc[2].push_back({ 0,0 }); loc[3].push_back({ 0,0 });
	for (int i = 0; i < 4; i++)
	{
		int fa = i;
		for (int j = 0; j < m; j++)
		{
			if (mov[j] == 'R') fa = (fa + 1) % 4;
			else if (mov[j] == 'L') fa = (fa - 1 == -1 ? 3 : fa - 1);
			else if (mov[j] == 'F')
			{
				int x = loc[i].back().first, y = loc[i].back().second;
				loc[i].push_back({ x + d[fa][0], y + d[fa][1] });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> r >> c;
	for (int i = 0; i < r; i++) cin >> g[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> mov[i];
	init();
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (loc[k].back().first + i < 0 || loc[k].back().first + i > r) continue;
				if (loc[k].back().second + j < 0 || loc[k].back().second + j > c) continue;
				bool flag = false;
				int x, y;
				for (auto m : loc[k])
				{
					x = m.first + i, y = m.second + j;
					if (x < 0 || x > r || y < 0 || y > c || g[x][y] == 'X') { flag = true; break; }
				}
				if (!flag) g[x][y] = '*';
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << g[i][j];
		}
		cout << '\n';
	}

	return 0;
}