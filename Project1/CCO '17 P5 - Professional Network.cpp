#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;

inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}


struct node
{
	int num, cost;
	bool operator<(const node &n) const
	{
		return num < n.num;
	}
} a[N];
priority_queue<int, vector<int>, greater<int>> q;
int n, cnt, res;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd();
	for (int i = 1; i <= n; i++)
		a[i].num = rd(), a[i].cost = rd();
	sort(a + 1, a + n + 1);

	for(int i = n; i >= 1; i--)
	{
		q.push(a[i].cost);

		//如果但剩下的人数不能满足第i个人的需求的时候，就挑一个最便宜的购买
		if (a[i].num > n - q.size())
			res += q.top(), q.pop();
	}
	cout << res;

	return 0;
}