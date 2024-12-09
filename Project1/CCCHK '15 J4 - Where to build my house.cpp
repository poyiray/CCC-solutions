#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
struct node
{
	int x, y;
	bool operator<(const node& n) const
	{
		if (x == n.x) return y < n.y;
		return x < n.x;
	}
};
node a[N];
vector<node> b;
int l, n, vis[N], res;

int main()
{
	cin >> l >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	
	sort(a + 1, a + n + 1);
	b.push_back({ 0,0 });
	for (int i = 1; i <= n; i++)
	{
		if (vis[i]) continue;
		int x = a[i].x, y = a[i].y;
		for (int j = i + 1; j <= n; j++)
		{
			if (min(a[j].y, y) >= max(a[j].x, x))
			{
				y = max(y, a[j].y);
				x = min(x, a[j].x);
				vis[j] = 1;
			}
		}
		b.push_back({ x, y });
	}
	if (b.back().y != l) b.push_back({ l,l });
	sort(b.begin(), b.end());
	for (int i = 1; i < b.size(); i++)
	{
		res = max(res, b[i].x - b[i - 1].y);
	}
	cout << res;

	return 0;
}