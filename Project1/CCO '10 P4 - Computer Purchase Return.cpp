#include <bits/stdc++.h>
using namespace std;

inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}

struct node { int c, v; };
const int N = 1e3 + 10, T = 7, C = 3e3 + 10;
int f[T][C], t, n, b;
node a[T][N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	t = rd(), n = rd();
	for (int i = 1; i <= n; i++)
	{
		int c = rd(), v = rd(), id = rd();
		a[id][++a[id][0].c] = { c, v };
	}
	for (int i = 1; i <= t; i++) if (!a[i][0].c) { cout << -1; return 0; };
	b = rd();

	for (int i = 1; i <= t; i++)
	{
		for (int j = 1; j <= a[i][0].c; j++)
		{
			for (int k = b; k >= a[i][j].c; k--)
			{
				f[i][k] = max(f[i][k], f[i - 1][k - a[i][j].c] + a[i][j].v);
			}
		}
	}
	cout << f[t][b];

	return 0;
}