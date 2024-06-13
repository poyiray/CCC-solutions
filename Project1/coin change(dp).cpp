#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10, M = 88;
int f[N], n, x, a[M];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	memset(f, 0x3f, sizeof f);
	cin >> x >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = a[i]; j <= x; j++)
		{
			if (j % a[i] == 0) f[j] = j / a[i];
			else f[j] = min(f[j], f[j - a[i]] + 1);
		}
	}
	cout << f[x];
	return 0;
}