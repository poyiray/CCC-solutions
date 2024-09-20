#include <bits/stdc++.h>
using namespace std;

const int N = 200;
int n, a[N][N], ie;

bool ck1()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (a[a[i][j]][k] != a[i][a[j][k]]) return 0;
			}
		}
	}
	return 1;
}

bool ck2()
{
	for (int i = 1; i <= n; i++)
	{
		bool f = true;
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] != j || a[j][i] != j)
			{
				f = false;
				break;
			}
		}
		if (f)
		{
			ie = i;
			return 1;
		}
	}
	return 0;
}

bool ck3()
{
	for (int i = 1; i <= n; i++)
	{
		bool f = true;
		for (int j = 1; j <= n; j++)
		{
			if (a[i][j] == ie && a[j][i] == ie)
			{
				f = false;
				break;
			}
		}
		if (f) return 0;
	}
	return 1;
}

int main()
{
	while (cin >> n && n)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) cin >> a[i][j];
		if (!ck1() || !ck2() || !ck3()) cout << "no\n";
		else cout << "yes\n";
	}

	return 0;
}