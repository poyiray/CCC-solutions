#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char g[30][30]; int c, r, n, n_room;
vector<int> total;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void dfs(int& sum, int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int a = x + dx[i], b = y + dy[i];
		if (a < 0 || a >= r || b < 0 || b >= c) continue;
		if (g[a][b] != '.') continue;
		g[a][b] = 'I';
		sum++;
		dfs(sum, a, b);
	}
}

int main()
{
	cin >> n >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> g[i];
	for(int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			if (g[i][j] != '.') continue;
			g[i][j] = 'I';
			int sum = 1;
			dfs(sum, i, j);
			total.push_back(sum);
		}

	sort(total.rbegin(), total.rend());
	for (auto val : total)
	{
		if (n - val >= 0)
		{
			n -= val;
			n_room++;
		}
		else break;
	}

	cout << n_room << (n_room > 1 || n_room == 0 ? " rooms, " : " room, ") << n << " square metre(s) left over";

	return 0;
}