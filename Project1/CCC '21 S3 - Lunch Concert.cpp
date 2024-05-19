#include <bits/stdc++.h> //真鸡巴难
using namespace std;
//使用三分
#define ll long long
const int N = 2e5 + 10;
int p[N], w[N], d[N], n;
ll res = LLONG_MAX;

// time it takes for everyone to move if concert is in the x position
ll move(int x)
{
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		int left = p[i] - d[i], right = p[i] + d[i];
		if (x >= left && x <= right) continue;
		int c = min(abs(x - left), abs(x - right));
		sum += (ll)w[i] * c;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	int l = 1e9, r = 0, m, m1;

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i] >> w[i] >> d[i];
		l = min(l, p[i]);
		r = max(r, p[i]);
	}
	
	l--, r++;
	while(l < r - 1)
	{
		m = (l + r) / 2;
		m1 = (m + r) / 2;
		ll x1 = move(m), x2 = move(m1);
		if (x1 <= x2)
		{
			res = min(res, x1);
			r = m1;
		}
		else
		{
			res = min(res, x2);
			l = m;
		}
	}
	cout << res;

	return 0;
}