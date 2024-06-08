#include <bits/stdc++.h>
using namespace std;

const int N = 110;
vector<int> num;
int n, vis[N], e[N];

//lcm(a,b) = a * b / gcd(a,b)
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int dfs(int x, int len)
{
	if (vis[x]) return len;
	vis[x] = 1;
	return dfs(e[x], len + 1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n && n)
	{
		memset(vis, 0, sizeof vis); num.clear();
		for (int i = 1; i <= n; i++)
		{
			int u, v; cin >> u >> v;
			e[u] = v;
		}
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i]) num.push_back(dfs(i, 0));
		}

		if (num.size() <= 1) { cout << num[0] << '\n'; continue; }
		
		int res = lcm(num[0], num[1]);
		for (int i = 2; i < num.size(); i++)
			res = lcm(res, num[i]);
		cout << res << '\n';
	}

	return 0;
}