#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10, M = 1e6;
int h[N], n, k;

bool judge(int x)
{
	int cnt = n;
	int i = 1, j = 2;
	while (i <= n)
	{
		int l1 = h[i] - x, r1 = h[i] + x;
		while (j <= n + 1 && max(l1, h[j] - x) <= min(r1, h[j] + x))
		{
			cnt--;
			j++;
		}
		i = j++;
	}
	return cnt <= k;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> h[i];
	cin >> k;
	sort(h + 1, h + n + 1);
	h[n + 1] = h[1] + M;

	int l = -1, r = M + 1;
	while (l + 1 != r)
	{
		int mid = l + r >> 1;
		if (judge(mid)) r = mid;
		else l = mid;
	}
	cout << r;

	return 0;
}