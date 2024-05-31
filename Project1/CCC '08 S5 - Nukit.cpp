#include <bits/stdc++.h>
using namespace std;

const int N = 31;
int n, a, b, c, d, f[N][N][N][N];

bool dfs(int a, int b, int c, int d)
{
	if (a < 0 || b < 0 || c < 0 || d < 0) return 1;
	if (f[a][b][c][d] != -1) return f[a][b][c][d];
	if (dfs(a - 2, b - 1, c, d - 2) && dfs(a - 1, b - 1, c - 1, d - 1) && dfs(a, b, c - 2, d - 1) && dfs(a, b - 3, c, d) && dfs(a - 1, b, c, d - 1))
		f[a][b][c][d] = 0;
	else f[a][b][c][d] = 1;
	return f[a][b][c][d];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	while (n--)
	{
		memset(f, -1, sizeof f);
		cin >> a >> b >> c >> d;
		if (dfs(a, b, c, d)) cout << "Patrick\n";
		else cout << "Roland\n";
	}

	return 0;
}