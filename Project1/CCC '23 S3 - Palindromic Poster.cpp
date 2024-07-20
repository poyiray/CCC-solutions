#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
int n, m, r, c;
char a[N][N];

void print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << a[i][j];
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> r >> c;

	if (n == r && m % 2 == 0 && c % 2 != 0) { cout << "IMPOSSIBLE"; return 0; }
	if (m == c && n % 2 == 0 && r % 2 != 0) { cout << "IMPOSSIBLE"; return 0; }

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = 'a';
	
	if (!r && !c)
	{
		a[1][1] = 'c';
		for (int i = 2; i <= m; i++) a[1][i] = 'b';
		for (int i = 2; i <= n; i++) a[i][1] = 'b';
		print();
		return 0;
	}

	if (n == r)
	{
		if (!c)
		{
			for (int i = 1; i <= m; i++) a[1][i] = 'b';
			print();
			return 0;
		}
		int len = m - c, left, right;
		if (c % 2 == 0)
		{
			left = right = m / 2;
			if (m % 2 != 0) left++, right++;
			else right++;

			for (int i = 1; i <= len; i += 2)
			{
				a[1][left--] = a[1][right++] = 'b';
			}
		}
		else
		{
			left = 1, right = m;
			for (int i = 1; i <= len; i += 2)
			{
				a[1][left++] = a[1][right--] = 'b';
			}
		}
		print();
		return 0;
	}
	else if (m == c)
	{
		if (!r)
		{
			for (int i = 1; i <= n; i++) a[i][1] = 'b';
			print();
			return 0;
		}
		int len = n - r, left, right;
		if (r % 2 == 0)
		{
			left = right = n / 2;
			if (n % 2 != 0) left++, right++;
			else right++;

			for (int i = 1; i <= len; i += 2)
			{
				a[left--][1] = a[right++][1] = 'b';
			}
		}
		else
		{
			left = 1, right = n;
			for (int i = 1; i <= len; i += 2)
			{
				a[left++][1] = a[right--][1] = 'b';
			}
		}
		print();
		return 0;
	}
	
	for (int i = r + 1; i <= n; i++)
	{
		for (int j = c + 1; j <= m; j++)
		{
			a[i][j] = 'b';
		}
	}
	if (!r)
	{
		for (int i = c + 1; i <= m; i++)
		{
			a[1][i] = 'c';
		}
	}
	else if (!c)
	{
		for (int i = r + 1; i <= n; i++)
		{
			a[i][1] = 'c';
		}
	}
	print();

	return 0;
}