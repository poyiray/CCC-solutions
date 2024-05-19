#include <bits/stdc++.h>
using namespace std;
bool st[1005][1005];
int g[1005][1005];
int n, m;

void dfs(int x)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (st[i][j]) continue;
			if (i * j == x)
			{
				if (i == n && j == m)
				{
					cout << "yes";
					exit(0);
				}
				st[i][j] = true;
				dfs(g[i][j]);
			}
		}
	}
		
}

int main()
{
	//freopen("input.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> g[i][j];

	st[1][1] = true;
	dfs(g[1][1]);
	cout << "no";

	return 0;
}