//比较难的一道题 主要思路就是找出一个区间内连续的数字 并且用k记录开头i记录结尾(双指针)
//之后对 j 进行迭代 当找到和 k 指向的数据一样的下标的时候 根据 j 和 [k,i] 区间的位置进行不同的操作
//如果 j > i 那么只要 其实只要 使用 L [k,j] 即可 不需要对 i 进行任何操作 同时这个操作的优先级是低的 因为需要确保之前的操作先被执行 这样才不会覆盖掉之前的数值
//如果 j < k 只要 使用 R [j, i] 即可 同时为了保证 j 所在的数值 不被之前的操作给覆盖 必须提高这个操作的优先级
//最后 j 处于 [k,j] 这个时候只需要 L [k, j] + R [j, i] 并且这个操作不会被之前的操作影响 直接使用push_back
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}

const int N = 4e5;

struct RES
{
	char c;
	int l, r;
};

int a[N], b[N], n, i, j, k;
deque<RES> res;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd();
	for (int i = 0; i < n; i++) a[i] = rd();
	for (int i = 0; i < n; i++) b[i] = rd();

	while (i < n)
	{
		while (b[i] == b[k] && i < n) i++; i--;
		while (b[k] != a[j] && j < n) j++;
		if (j >= n) { cout << "NO"; return 0; }
		if (j > i)
		{
			res.push_back({ 'L', k, j });
		}
		else if(j < k)
		{
			res.push_front({ 'R', j, i });
		}
		else if (j >= k && j <= i)
		{
			if(k != j) res.push_back({ 'L', k, j });
			if(j != i) res.push_back({ 'R', j, i });
		}
		k = ++i;
	}
	cout << "YES\n" << res.size() << '\n';
	for (auto& ans : res)
		cout << ans.c << " " << ans.l << " " << ans.r << '\n';

	return 0;
}