#include <bits/stdc++.h>
using namespace std;

//          #
//    #    ###
//#, ###, #####, etc.
//一个更大的三角形由它底部的三个三角形组成

const int N = 2e3 + 10;
char g[N][N];
int f[N][N], res, n;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> g[i] + 1;
	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			if (g[i][j] != '#') continue;
			f[i][j] = min({ f[i + 1][j], f[i + 1][j - 1], f[i + 1][j + 1] }) + 1;
			res += f[i][j];
		}
	}
	cout << res;

	return 0;
}