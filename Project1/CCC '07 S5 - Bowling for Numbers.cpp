#include <bits/stdc++.h>
using namespace std;
void wt(int x)
{
	if (x > 9)
		wt(x / 10);
	putchar(x % 10 + '0');
	return;
}

inline int rd()
{
	int x = 0;
	char ch = getchar();
	while (ch<'0' || ch>'9')
		ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}


const int N = 3e4 + 10, K = 510;
int t, n, k, w, f[K][N]; //在丢第k个球的时候 [n-i]个球中能够获得的最大价值
int a[N], sum[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	//freopen("out.txt", "w", stdout);
	t = rd();
	while (t--)
	{
		n = rd(), k = rd(), w = rd();
		for (int i = 1; i <= n; i++) a[i] = rd();

		//找出每个片段的和
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < w; j++)
			{
				sum[i] += a[i + j];
			}
		}

		for (int i = 1; i <= k; i++)
		{
			for (int j = n; j >= 1; j--)
			{
				f[i][j] = max(f[i][j + 1], sum[j] + f[i - 1][j + w]);
			}
		}
		wt(f[k][1]); putchar('\n');
		for (int i = 1; i <= k; i++)
			fill(f[i], f[i] + n + 1, 0);
		fill(sum, sum + n + 1, 0);
	}

	return 0;
}