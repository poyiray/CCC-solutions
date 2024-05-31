#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 10;
int n, t;
bool a[N], b[N];
char s[N];

int power()
{
	int res = 1;
	while ((res <<= 1) <= t);
	return res >> 1;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	//freopen("out.txt", "w", stdout);
	cin >> n >> t >> s + 1;
	for (int i = 1; i <= n; i++)
		if (s[i] == '1') a[i] = 1;

	bool *f = a, *s = b, *temp;
	while (t > 0)
	{
		int p = power();
		t -= p;
		for (int i = 1; i <= n; i++)
		{
			int r = (i + p - 1) % n + 1, l = ((i - p - 1 + n) % n + n) % n + 1;
			s[i] = f[r] ^ f[l];
		}
		temp = f;
		f = s;
		s = temp;
	}
	for (int i = 1; i <= n; i++)
		putchar(f[i] + '0');

	return 0;
}