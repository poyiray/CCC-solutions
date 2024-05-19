#include <bits/stdc++.h>
using namespace std;

const int N = 6000;
int k, n, m, cycle[N], cnt;

void bs()
{
	int l = 0, r = 5010, mid = 0;
	while (l + 1 != r)
	{
		int mid = (l + r) / 2;
		if (mid * (mid - 1) / 2 <= k) l = mid; // 一个圈内的完美组合一共就是 n * (n - 1) / 2; 需要找到最大的圈
		else r = mid;
	}
	cycle[++cnt] = l;
	k -= (l * (l - 1) / 2);
	n += l;
	m += l + 1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> k;
	if (!k) { cout << 0 << " " << 0; return 0; }
	while (k) bs();
	cout << n << " " << --m << '\n';
	int u = 0;
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 1; j < cycle[i]; j++) 
			cout << j + u << " " << j + 1 + u << '\n';
		cout << u + cycle[i] << " " << u + 1 << '\n';
		u += cycle[i];
		if (i != cnt) cout << u << " " << u + 1 << '\n';
	}

	return 0;
}