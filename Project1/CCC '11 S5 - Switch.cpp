#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 25) + 1;
int n, vis[N];

void ck(int loc, int &x)
{
	int l, r;
	l = r = loc;
	for (int i = loc - 1; i >= 0; i--)
	{
		if (!(x >> i & 1)) break;
		l--;
	}
	for (int i = loc + 1; i < n; i++)
	{
		if (!(x >> i & 1)) break;
		r++;
	}
	if (r - l + 1 >= 4)
	{
		int mask = ((1 << r + 1) - 1) ^ (1 << l) - 1;
		x ^= mask;
	}
}

int main()
{
	cin >> n;
	int num = 0;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		num = (num << 1) | x;
	}

	queue<pair<int, int>> q;
	q.push({ num, 0 });
	while (q.size())
	{
		int cnt = q.front().second, x = q.front().first; q.pop();
		if (!x)
		{
			cout << cnt;
			return 0;
		}
		int id = x;
		for (int i = 0; i < n; i++)
		{
			x = id;
			if (i == 0)
			{
				if (x & 1 << (i + 1) && !(x >> i & 1))
				{
					x |= 1 << i;
					ck(i, x);
					if (vis[x]) continue;
					vis[x] = 1;
					q.push({ x, cnt + 1 });
				}
			}
			else if (i == n - 1)
			{
				if (x & 1 << (i - 1) && !(x >> i & 1))
				{
					x |= 1 << i;
					ck(i, x);
					if (vis[x]) continue;
					vis[x] = 1;
					q.push({ x, cnt + 1 });
				}
			}
			else
			{
				if ((x & 1 << (i - 1) || x & 1 << (i + 1)) && !(x >> i & 1))
				{
					x |= 1 << i;
					ck(i, x);
					if (vis[x]) continue;
					vis[x] = 1;
					q.push({ x, cnt + 1 });
				}
			}
		}
	}

	return 0;
}