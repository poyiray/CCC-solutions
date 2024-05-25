#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}

const int N = 5010;
int a[N], b[N], n, arr[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd();
	for (int i = 1; i <= n; i++) arr[i] = rd();

	for (int i = 1; i <= n; i++)
	{
		int r = n, l = n - i + 1, minn = INT_MAX;
		if (i & 1) //ÆæÊý
		{
			while (l >= 1)
			{
				a[r] = a[r - 1] + abs(arr[l] - arr[r]);
				minn = min(a[r], minn);
				r--, l--;
			}
		}
		else //Å¼Êý
		{
			while (l >= 1)
			{
				b[r] = b[r - 1] + abs(arr[l] - arr[r]);
				minn = min(b[r], minn);
				r--, l--;
			}
		}
		cout << minn << ' ';
	}

	return 0;
}