//高精度加法 + dfs 排列
#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3;
int num[N], pos[N], cnt, n1[N], n2[N], n3[N], sum[N];
bool vis[N];
string s1, s2, s3;

//高精度加法
bool ck()
{
	int len = max(s1.size(), s2.size()); sum[len] = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		n1[i] = num[pos[s1[i]]];
	}
	for (int i = 0; i < s2.size(); i++)
	{
		n2[i] = num[pos[s2[i]]];
	}
	for (int i = 0; i < s3.size(); i++)
	{
		n3[i] = num[pos[s3[i]]];
	}

	for (int i = 0; i < len; i++)
	{
		sum[i] = n1[i] + n2[i];
 	}

	for (int i = 0; i < len; i++)
	{
		if (sum[i] >= 10)
		{
			sum[i + 1] += sum[i] / 10;
			sum[i] %= 10;
		}
	}
	if (sum[len]) len++;
	bool f = true;
	if (len == s3.size())
	{
		for (int i = 0; i < s3.size(); i++)
		{
			if (n3[i] != sum[i]) { f = false; break; }
		}
	}
	else f = false;

	if (f)
	{
		for (int i = s1.size() - 1; i >= 0; i--)
		{
			cout << n1[i];
		}
		cout << '\n';
		for (int i = s2.size() - 1; i >= 0; i--)
		{
			cout << n2[i];
		}
		cout << '\n';
		for (int i = s3.size() - 1; i >= 0; i--)
		{
			cout << n3[i];
		}
		cout << '\n';
	}

	return f;
}

bool dfs(int x)
{
	if (x > cnt)
	{
		if (ck()) return 1;
		return 0;
	}
	for (int i = 0; i <= 9; i++)
	{
		if ((x == pos[s1.back()] || x == pos[s2.back()] || x == pos[s3.back()]) && i == 0) continue;
		if (vis[i]) continue;
		num[x] = i;
		vis[i] = 1;
		bool f = dfs(x + 1);
		vis[i] = 0;
		if (f) return 1;
	}
	return 0;
}

void solve()
{
	cin >> s1 >> s2 >> s3;
	for (auto &c : s1)
	{
		if (!pos[c]) pos[c] = ++cnt;
	}
	for (auto &c : s2)
	{
		if (!pos[c]) pos[c] = ++cnt;
	}
	for (auto &c : s3)
	{
		if (!pos[c]) pos[c] = ++cnt;
	}
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	reverse(s3.begin(), s3.end());
	dfs(1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int _; cin >> _;
	while (_--)
	{
		solve();
		cout << '\n';
		for (auto &c : s1) pos[c] = 0;
		for (auto &c : s2) pos[c] = 0;
		for (auto &c : s3) pos[c] = 0;
		cnt = 0;
	}

	return 0;
}