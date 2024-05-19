#include <bits/stdc++.h>
using namespace std;

int a[4], n;

int cul(int i, int x, int y)
{
	switch (i)
	{
	case 0: return x + y;
	case 1: return x - y;
	case 2: return x * y;
	case 3: return y && x % y == 0 ? x / y : INT_MIN;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("out.txt", "w", stdout);
	cin >> n;
	while (n--)
	{
		int res = 0;
		for (int i = 0; i < 4; i++) cin >> a[i];
		sort(a, a + 4);
		do
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					for (int k = 0; k < 4; k++)
					{
						int ans;
						if ((ans = cul(i, a[0], a[1])) != INT_MIN)
							if ((ans = cul(j, ans, a[2])) != INT_MIN)
								if ((ans = cul(k, ans, a[3])) != INT_MIN)
									if (ans <= 24) res = max(ans, res);

						int ans2; // 还有一种两边加括号的情况
						if ((ans = cul(i, a[0], a[1])) != INT_MIN)
							if ((ans2 = cul(k, a[2], a[3])) != INT_MIN)
								if ((ans = cul(j, ans, ans2)) != INT_MIN)
									if (ans <= 24) res = max(ans, res);
					}
				}
			}
			for (int i = 0; i < 4; i++) cout << a[i] << " ";
			cout << endl;
		} while (next_permutation(a, a + 4));
		cout << res << '\n';
	}

	return 0;
}