#include <bits/stdc++.h>
using namespace std;

const int N = 200;
int g[N][N][N], n;

void print(int idx)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << g[idx][i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) cin >> g[1][i][j];

	for (int idx = 2; idx <= 4; idx++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				g[idx][i][j] = g[idx - 1][j][abs(i - n - 1) % (n + 1)];
			}
		}
	}

	for (int idx = 1; idx <= 4; idx++)
	{
		bool f = false;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n - 1; j++)
			{
				if (g[idx][i][j] > g[idx][i][j + 1]) f = true;
			}
		}
		for (int i = 1; i <= n - 1; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (g[idx][i][j] > g[idx][i + 1][j]) f = true;
			}
		}
		if (!f) { print(idx); break; }
	}

	return 0;
}