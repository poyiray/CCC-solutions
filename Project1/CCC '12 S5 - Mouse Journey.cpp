#include <bits/stdc++.h>
using namespace std;

const int N = 26;
int r, c, k, mem[N][N], f[N][N];

//int dfs(int x, int y)
//{
//	if (x > r || y > c || !mem[x][y]) return 0;
//	if (mem[x][y] != -1) return mem[x][y];
//	if (x == r && y == c) return 1;
//	mem[x][y] = dfs(x + 1, y) + dfs(x, y + 1);
//	return mem[x][y];
//}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> r >> c >> k;
	while (k--)
	{
		int x, y; cin >> x >> y;
		//mem[x][y] = 0;
		mem[x][y] = 1;
	}
	f[r][c] = 1;
	for (int i = r; i >= 1; i--)
	{
		for (int j = c; j >= 1; j--)
		{
			if (mem[i][j] || (i == r && j == c)) continue;
			f[i][j] = f[i + 1][j] + f[i][j + 1];
		}
	}
	cout << f[1][1];

	return 0;
}