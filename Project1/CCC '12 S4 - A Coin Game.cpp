#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int n, res = INT_MAX;
vector<int> s[N];

void dfs(int x, int u, int v)
{
	for (int i = 1; i <= n; i++)
	{
		for (auto v : s[i])
		{
			cout << v << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		if (!s[i].size()) continue;
		if(i != v || i + 1 != u)
		if (!s[i + 1].size() || s[i].back() < s[i + 1].back())
		{
			s[i + 1].push_back(s[i].back());
			s[i].pop_back();
			dfs(x + 1, i, i + 1);
			s[i].push_back(s[i + 1].back());
			s[i + 1].pop_back();
		}

		else if(i != v || i - 1 != u)
		if (!s[i - 1].size() || s[i].back() < s[i - 1].back())
		{
			s[i - 1].push_back(s[i].back());
			s[i].pop_back();
			dfs(x + 1, i, i - 1);
			s[i].push_back(s[i - 1].back());
			s[i - 1].pop_back();
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (s[i - 1].size() > 1 || s[i].size() > 1) return;
		if (s[i - 1].back() > s[i].back()) return;
	}
	res = min(res, x);
}

int main()
{
	while (cin >> n && n)
	{
		s[0].push_back(INT_MIN);
		s[n + 1].push_back(INT_MIN);
		for (int i = 1; i <= n; i++)
		{
			int x; cin >> x;
			s[i].push_back(x);
		}
		cout << endl;
		dfs(0, 0, 0);
		cout << res << '\n';
	}

	return 0;
}