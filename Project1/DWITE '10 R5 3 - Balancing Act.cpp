#include <bits/stdc++.h>
using namespace std;

//可以把这个找差值的问题转换为背包问题
//让数值不断地逼近 中间值
//越靠近中间值差值就越小

const int N = 40, M = 1e4 + 10;
int f[M], n, w[N];

void solve()
{
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i];
		sum += w[i];
	}

	int mid = sum & 1 ? sum / 2 + 1 : sum / 2;
	for (int i = 1; i <= n; i++)
	{
		for (int j = mid; j >= w[i]; j--)
		{
			f[j] = max({ f[j], f[j - w[i]] + w[i] });
		}
	}
	cout << abs(sum - 2 * f[mid]) << "\n";
	memset(f, 0, sizeof f);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	for (int i = 1; i <= 5; i++) solve();

	return 0;
}