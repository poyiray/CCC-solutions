#include <bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}


const int N = 1e5 + 10;
int a[N], n;

void solve()
{
	n = rd() - 1;
	int len = 1; a[1] = rd();
	while (n--)
	{
		int x = rd();
		if (x > a[len]) a[++len] = x;
		else
		{
			int l = 0, r = len + 1;
			while (l + 1 != r)
			{
				int mid = l + r >> 1;
				if (x > a[mid]) l = mid;
				else r = mid;
			}
			a[r] = x;
		}
	}
	cout << len << '\n';
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int _ = rd();
	while (_--) solve();

	return 0;
}