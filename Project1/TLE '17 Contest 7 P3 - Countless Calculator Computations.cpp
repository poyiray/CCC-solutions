#include <bits/stdc++.h>
using namespace std;

const double N = 1e-1;
int q, y, z;
long double l, r, m;

bool judge(double x)
{
	long double n = x;
	for (int i = 0; i < y - 1; i++)
	{
		n = pow(x, n);
	}
	if (abs(n - z) <= N)
	{
		return 1;
	}
	else
	{
		if (n - z > N) r = m;
		else if (n - z < -N) l = m;
		return 0;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> q;
	while (q--)
	{
		cin >> y >> z;
		l = 0, r = 10, m = (l + r) / 2;
		while(!judge(m))
		{
			m = (l + r) / 2;
		}
		cout << fixed << setprecision(20) << m << '\n';
	}

	return 0;
}