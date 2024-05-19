#include <bits/stdc++.h>
using namespace std;

struct BOX
{
	int l, w, h, v, id;
	bool operator<(const BOX& b) const
	{
		return v < b.v;
	}
};

const int N = 1010;
BOX a[N], b[N];
int res[N];
int n, m;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int l, w, h; cin >> l >> w >> h;
		a[i] = { l,w,h,l*w*h };
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int l, w, h; cin >> l >> w >> h;
		b[i] = { l,w,h,l*w*h, i};
	}

	sort(a, a + n);
	for (int i = 0; i < m; i++)
	{
		bool flag = false;
		for (int j = 0; j < n; j++)
		{
			if (b[i].v <= a[j].v)
			{
				if (	(b[i].l <= a[j].l && b[i].w <= a[j].w && b[i].h <= a[j].h)
					||  (b[i].w <= a[j].l && b[i].l <= a[j].w && b[i].h <= a[j].h)
					||  (b[i].w <= a[j].l && b[i].h <= a[j].w && b[i].l <= a[j].h)
					||  (b[i].h <= a[j].l && b[i].w <= a[j].w && b[i].l <= a[j].h)
					||  (b[i].l <= a[j].l && b[i].h <= a[j].w && b[i].w <= a[j].h)
					||  (b[i].h <= a[j].l && b[i].l <= a[j].w && b[i].w <= a[j].h))
				{
					res[b[i].id] = a[j].v;
					flag = true;
					break;
				}
			}
		}
		if (!flag) res[b[i].id] = -1;
	}
	for (int i = 0; i < m; i++)
	{
		if (res[i] == -1) cout << "Item does not fit.";
		else cout << res[i];
		cout << endl;
	}

	return 0;
}