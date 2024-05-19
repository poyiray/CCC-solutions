#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[2][N], n, k;

int main()
{
	cin >> n;
	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= n; j++) cin >> a[i][j];

	for (int i = 1; i <= n; i++)
	{
		if ((a[0][i] += a[0][i - 1]) == (a[1][i] += a[1][i - 1]))
		{
			k = i;
		}
	}
	cout << k;
	return 0;
}