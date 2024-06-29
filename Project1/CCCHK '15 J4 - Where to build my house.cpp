#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct node
{
	ll x, y;
	bool operator<(const node& n) const
	{
		return y < n.y;
	}
};
const int N = 1e5 + 10;
ll L, n, res;
node a[N];

int main()
{
	cin >> L >> n;
	a[n + 1].x = a[n + 1].y = L;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].y;
		if (a[i].x == 0 && a[i].y == L) { cout << 0; return 0; };
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n + 1; i++)
	{
		if ((a[i].x >= a[i - 1].x && a[i].x <= a[i - 1].y) || (a[i].x >= a[i + 1].x && a[i].x <= a[i + 1].y)) continue;
		int l = -1, r = i;
		while (l + 1 != r)
		{
			int mid = (l + r) / 2;
			if (a[mid].y < a[i].x) l = mid;
			else r = mid;
		}
		res = max(res, a[i].x - a[l].y);
	}
	cout << res;
	return 0;
}