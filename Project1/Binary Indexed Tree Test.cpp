#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, m, num[N], t[N], a[N]; //num[] 维护每个数的数量前缀和
int lowbit(int x) { return x & -x; }

void add(int x, int v, int p, int *a)
{
	for (int i = x; i <= p; i += lowbit(i)) a[i] += v;
}

int sum(int x, int *a)
{
	int res = 0;
	for (int i = x; i > 0; i -= lowbit(i)) res += a[i];
	return res;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		add(i, a[i], n, t);
		add(a[i], 1, N, num);
	}

	while (m--)
	{
		char op; cin >> op;
		if (op == 'C')
		{
			int x, v; cin >> x >> v;
			add(x, v - a[x], n, t);
			add(a[x], -1, N, num);
			add(v, 1, N, num);
			a[x] = v;
		}
		else if (op == 'Q')
		{
			int x; cin >> x;
			cout << sum(x, num) << '\n';
		}
		else
		{
			int l, r; cin >> l >> r;
			cout << sum(r, t) - sum(l - 1, t) << '\n';
		}
	}

	return 0;
}