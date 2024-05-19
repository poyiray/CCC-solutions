#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct node
{
	ll x, y;
	bool operator<(const node& n) const { return x < n.x; }
};
const int N = 1e5 + 10;
ll L, n, res, my;
node a[N];

int main()
{
	cin >> L >> n;
	a[0].x = a[0].y = 0;
	a[n + 1].x = a[n + 1].y = L;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		my = max(a[i].y, my);
		if (a[i].x <= a[i - 1].y && a[i].x >= a[i].x) continue;
		res = max(res, a[i].x - a[i - 1].y);
	}
	res = max(res, a[n + 1].y - my);
	cout << res;
	return 0;
}