#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N][N], n;

struct bigNum
{
	int num[N], len;
	void operator+=(const bigNum& n)
	{
		len = max(n.len, len);
		for (int i = 1; i <= len; i++)
		{
			num[i] += n.num[i];
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
		if (num[len + 1]) len++;
	}
	friend ostream &operator<<(ostream&, bigNum& b);
};
ostream &operator<<(ostream &out, bigNum &b)
{
	out << b.num[b.len];
	for (int i = b.len - 1; i >= 1; i--)
	{
		out << b.num[i];
	}
	return out;
}
bigNum f[N][N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> a[i][j];

	f[1][1].num[1] = f[1][1].len = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == n && j == n) continue;
			f[i + a[i][j]][j] += f[i][j];
			f[i][j + a[i][j]] += f[i][j];
		}
	}
	cout << f[n][n];

	return 0;
}