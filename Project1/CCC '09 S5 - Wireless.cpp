#include <bits/stdc++.h>
using namespace std;

//主要想法是2维圆形的差分不好做，可以考虑用映射来转换为1维差分
const int N = 3e7 + 10;
int d[N], n, m, k;

inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), m = rd(), k = rd();

	while (k--)
	{
		int y = rd(), x = rd(), r = rd(), b = rd();

		for (int i = 1; i <= r; i++)
		{
			if (x - i < 1) break;
			int len = sqrt(r * r - i * i), row = (x - i - 1) * m;
			d[row + max(1, y - len)] += b;
			d[row + min(m + 1, y + len + 1)] -= b;
		}

		for (int i = 1; i <= r; i++)
		{
			if (x + i > n) break;
			int len = sqrt(r * r - i * i), row = (x + i - 1) * m;
			d[row + max(1, y - len)] += b;
			d[row + min(m + 1, y + len + 1)] -= b;
		}
		
		int row = (x - 1) * m;
		d[row + max(1, y - r)] += b;
		d[row + min(m + 1, y + r + 1)] -= b;
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