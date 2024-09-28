#include <bits/stdc++.h>
using namespace std;

const int N = 53;
int a[N][N], f[N][N][N][N], n, m;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = i + 1; k <= n; k++)
			{
				for (int l = 1; l < j; l++)
				{
					f[i][j][k][l] = max({
						f[i - 1][j][k - 1][l],
						f[i][j - 1][k][l - 1],
						f[i - 1][j][k][l - 1],
						f[i][j - 1][k - 1][l]
						}) + a[i][j] + a[k][l];
				}
			}
		}
	}
	cout << f[n - 1][m][n][m - 1];
	return 0;
}