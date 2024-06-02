#include <bits/stdc++.h>
using namespace std;

const int N = 410;
int n, f[N][N], res;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> f[i][i];
		res = max(f[i][i], res);
	}
	for (int len = 2; len <= n; len++)
	{
		for (int l = 1, r = len; r <= n; l++, r++)
		{
			for (int k = l; k < r; k++)
			{
				if (f[l][k] && f[k + 1][r] && f[l][k] == f[k + 1][r])
				{
					f[l][r] = f[l][k] + f[k + 1][r];
					break;
				}
			}

			for (int k1 = l, k2 = r; k1 < k2 - 1;)
			{
				if (f[l][r]) break; //这个区间依旧被合并就算了
				
				if (!f[l][k1]) k1++;
				else if (!f[k2][r]) k2--;
				else if (f[l][k1] == f[k2][r])
				{
					if (f[k1 + 1][k2 - 1])
						f[l][r] = f[l][k1] + f[k1 + 1][k2 - 1] + f[k2][r];
					else k1++, k2--;
				}
				else if (f[l][k1] < f[k2][r]) k1++; //如果左区间太小那就试着扩大
				else if (f[l][k1] > f[k2][r]) k2--; //右边也一样
			}
			res = max(res, f[l][r]);
		}
	}
	cout << res;
	return 0;
}