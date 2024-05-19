#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x = 0;
	char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}

#define ll long long
const int N = 1e5 + 10;
ll n, w, c[N];

//由于进行过排序，所以本质上最小的差值就是a[1] 到 a[n]的差值
//例如: 1 3 5 7 9
//差值为 2 + 2 + 2 + 2 = 9 - 1
//情况1 如果 w 在 1-n 的范围内，那么不会影响结果
//情况2 如果 w 比 1-n 小 那么结果就是 w-n 的绝对值
//情况3 如果 w 比 1-n 大 那么结果就是 1-w 的绝对值
ll getMin() { return max(w - c[1], 0ll) + max(c[n] - w, 0ll); }

//求最大的差值 就是 1-n + 2-(n-1)..... 的差的和
//并且由于先喝的水那么在刚开始的时候呢就会有两种结果
ll getMax()
{
	ll l = 1, r = n, res1 = 0, res2 = 0, last = w;
	for (int i = 1; i <= n; i++) // 先左
	{
		if (i % 2)
			res1 += max(abs(c[l] - w), abs(c[l] - last)), last = c[l++];
		else
			res1 += max(abs(c[r] - w), abs(c[r] - last)), last = c[r--];
	}
	last = w, l = 1, r = n;
	for (int i = 1; i <= n; i++) // 再右
	{
		if (i % 2)
			res2 += max(abs(c[r] - w), abs(c[r] - last)), last = c[r--];
		else
			res2 += max(abs(c[l] - w), abs(c[l] - last)), last = c[l++];
	}
	return max(res1, res2);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), w = rd();
	for (int i = 1; i <= n; i++) c[i] = rd();
	sort(c + 1, c + n + 1);
	cout << getMin() << ' ' << getMax();
	return 0;
}