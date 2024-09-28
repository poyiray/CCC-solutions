#include <bits/stdc++.h>
using namespace std;
#define int long long
char *p1, *p2, buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int rd()
{
	int x = 0;
	char ch = nc();
	while (ch < 48 || ch>57) ch = nc();
	while (ch >= 48 && ch <= 57) x = x * 10 + ch - 48, ch = nc();
	return x;
}

const int N = 2e6 + 10;
int cnt[N], n, c, res, op, sum[N];

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), c = rd();
	op = c / 2, res = n * (n - 1) * (n - 2) / 6;
	for (int i = 1; i <= n; i++)
	{
		int x = rd();
		cnt[x]++;
		cnt[c + x]++;
	}
	for (int i = 0; i < c * 2; i++) sum[i] = sum[i - 1] + cnt[i];

	for (int i = 0; i < c; i++)
	{
		int a = cnt[i], b = sum[i + op] - sum[i];
		res -= a * b * (b - 1) / 2;
		res -= b * a * (a - 1) / 2;
		res -= a * (a - 1) * (a - 2) / 6;
	}
	if (c % 2 == 0)
	{
		for (int i = 0; i < op; i++)
		{
			int a = cnt[i], b = cnt[i + op];
			res += a * b * (b - 1) / 2;
			res += b * a * (a - 1) / 2;
		}
	}
	cout << res;

	return 0;
}