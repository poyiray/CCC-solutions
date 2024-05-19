#include <bits/stdc++.h>
using namespace std;

const int N = 400;
int n;
bool vis[N];
bool a[N];
vector<vector<char>> e(N);
vector<set<char>> ans(N);

void qwq(char u)
{
	for (char v : e[u])
	{
		if (vis[v]) continue;
		if (islower(v)) { ans[u].insert(v); continue; }
		vis[v] = 1;
		qwq(v);
		for (auto val : ans[v]) ans[u].insert(val);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	string s;
	while (n--)
	{
		char u, v;
		cin >> u >> s >> v;
		if (isupper(u)) a[u] = 1;
		if (isupper(v)) a[v] = 1;
		e[u].push_back(v);
	}
	for (char i = 'A'; i <= 'Z'; i++)
	{
		if (!a[i]) continue;
		memset(vis, 0, sizeof vis);
		vis[i] = 1;
		qwq(i);
	}
	for (char i = 'A'; i <= 'Z'; i++)
	{
		if (!a[i]) continue;
		if (!ans[i].size()) { cout << i << " = " << "{}\n"; continue; };
		cout << i << " = {" << *ans[i].begin();
		for (auto it = ++ans[i].begin(); it != ans[i].end(); it++)
			cout << ',' << *it;
		cout << "}\n";
	}

	return 0;
}