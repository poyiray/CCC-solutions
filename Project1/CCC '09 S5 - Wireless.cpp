#include <bits/stdc++.h>
using namespace std;

//主要想法是2维圆形的差分不好做，可以考虑用映射来转换为1维差分
const int N = 3e7 + 10;
int d[N], n, m, k, arr[100000];

inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}


inline int idx(int i, int j)
{
	//边界的判断
	j = max(1, j); j = min(j, m + 1);
	return m * (i - 1) + j;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), m = rd(), k = rd();

	while (k--)
	{
		int y = rd(), x = rd(), r = rd(), b = rd();

		int cnt = 0;
		for (int i = 1; i <= r; i++) arr[++cnt] = sqrt(r * r - i * i);

		for (int i = 1; i <= r; i++)
		{
			if (x - i < 1) break;
			int len = arr[i];
			d[idx(x - i, y - len)] += b;
			d[idx(x - i, y + len + 1)] -= b;
		}

		for (int i = 1; i <= r; i++)
		{
			if (x + i > n) break;
			int len = arr[i];
			d[idx(x + i, y - len)] += b;
			d[idx(x + i, y + len + 1)] -= b;
		}
		
		d[idx(x, y - r)] += b;
		d[idx(x, y + r + 1)] -= b;
	}

	for (int i = 1; i <= n * m; i++) d[i] += d[i - 1];

	int maxn = 0, num = 0;
	for (int i = 1; i <= n * m; i++)
	{
		if (maxn < d[i])
		{
			maxn = d[i];
			num = 1;
		}
		else if (maxn == d[i]) num++;
	}
	cout << maxn << '\n' << num;

	return 0;
}