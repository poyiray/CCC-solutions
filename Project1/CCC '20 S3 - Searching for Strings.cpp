#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 10, P1 = 131, P2 = 137, M = 1e9 + 7;
int p1[N], h1[N], p2[N], h2[N], n, m, cnt[N], t, res, vis[N];
set<int> ans;
char a[N], b[N];

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> a + 1 >> b + 1; m = strlen(a + 1), n = strlen(b + 1);
	for (int i = 1; i <= m; i++)
	{
		if (!cnt[a[i]]++) t++, vis[a[i]] = 1;
	}

	p1[0] = 1, p2[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		p1[i] = (p1[i - 1] * P1) % M;
		p2[i] = (p2[i - 1] * P2) % M;
		h1[i] = (h1[i - 1] * P1 + b[i]) % M;
		h2[i] = (h2[i - 1] * P2 + b[i]) % M;
	}

	for (int i = 1; i <= n; i++)
	{
		if (vis[b[i]] && !--cnt[b[i]]) t--;
		if (i > m && vis[b[i - m]] && !cnt[b[i - m]]++) t++;

		if (!t)
		{
			int k1 = (h1[i] - h1[i - m] * p1[m] % M + M) % M;
			int k2 = (h2[i] - h2[i - m] * p2[m] % M + M) % M;
			ans.insert((k1 << 31) | k2);
		}
	}
	cout << ans.size();

	return 0;
}