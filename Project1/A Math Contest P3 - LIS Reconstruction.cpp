#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N], n, res[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) res[i] = i;
	int maxn = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != maxn && a[i] != maxn + 1) { cout << -1; return 0; }
		maxn = a[i];
	}

	int i = 1, j = 1, cnt = 0;
	while (i <= n)
	{
		while (j < n + 1 && a[i] == a[j]) j++;
		while (j < n + 1 && a[i] == a[j]) j++;
		reverse(res + i, res + j);
		i = j;
	}
	for (int i = 1; i <= n; i++) cout << res[i] << " ";

	return 0;
