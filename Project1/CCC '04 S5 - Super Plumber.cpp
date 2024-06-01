#include <bits/stdc++.h>
//细节很多的dp
using namespace std;

inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}

const int N = 101;
int a[N][N], n, m, f[N][N], up[N], down[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	while ((n = rd(), m = rd()) && n)
	{
		memset(a, 0, sizeof a);
		memset(f, 0, sizeof f);
		memset(down, 0, sizeof down);
		memset(up, 0, sizeof up);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				char c = getchar();
				if (c == '*') a[i][j] = -1;
				else if (isalnum(c)) a[i][j] = c - '0';
			}
			getchar();
		}

		for (int i = n; i >= 1; i--)
			f[i][1] = f[i + 1][1] + a[i][1];
		for (int i = 2; i <= m - 1; i++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (a[k][i] == -1 || a[k][i - 1] == -1) down[k] = up[k] = INT_MIN;
				else up[k] = down[k] = f[k][i - 1] + a[k][i];
			}
			for (int k = 1; k <= n; k++)
			{
				if (a[k][i] == -1 || a[k - 1][i] == -1) continue;
				down[k] = max(down[k], down[k - 1] + a[k][i]);
			}
			for (int k = n; k >= 1; k--)
			{
				if (a[k][i] == -1 || a[k + 1][i] == -1) continue;
				up[k] = max(up[k], up[k + 1] + a[k][i]);
			}
			for (int k = 1; k <= n; k++) f[k][i] = max(up[k], down[k]);
			memset(down, 0, sizeof down);
			memset(up, 0, sizeof up);
		}

		for (int k = 1; k <= n; k++)
		{
			if (a[k][m] == -1 || a[k][m - 1] == -1) continue;
			down[k] = f[k][m - 1] + a[k][m];
		}
		for (int k = 1; k <= n; k++)
		{
			if (a[k][m] == -1 || a[k - 1][m] == -1) continue;
			down[k] = max(down[k], down[k - 1] + a[k][m]);
		}
		cout << down[n] << '\n';
	}


	return 0;
}