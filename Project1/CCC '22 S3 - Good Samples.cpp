#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 10;
int a[N], cnt, n, m, pos;
ll k;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> k;
	if (k < n)
	{
		cout << -1;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int remain = n - i;
		int tmp = min(k - remain, (long long)m); // 预计可以加多少
		if (i > tmp) a[i] = a[i - tmp];
		else a[i] = i, tmp = i;
		k -= tmp;
	}
	if (k) { cout << -1; return 0; };
	for (int i = 1; i <= n; i++) cout << a[i] << " ";

	return 0;
}