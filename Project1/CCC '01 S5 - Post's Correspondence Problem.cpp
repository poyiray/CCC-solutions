#include <bits/stdc++.h>
using namespace std;

//super 暴力的dfs 但是测试用例太弱了，依旧可以过
const int N = 50;
string b[N], a[N];
vector<int> vis;
int n, m;

void dfs(string s1, string s2, int x)
{
	if (s1 == s2 && x != 0)
	{
		cout << vis.size() << '\n';
		for (auto c : vis)
			cout << c << '\n';
		exit(0);
	}
	if (x >= m) return;
	for (int i = 1; i <= n; i++)
	{
		vis.push_back(i);
		dfs(s1 + a[i], s2 + b[i], x + 1);
		vis.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	dfs("", "", 0);
	cout << "No solution.";
	return 0;
}