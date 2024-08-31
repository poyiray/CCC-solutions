#include <bits/stdc++.h>
using namespace std;

const int N = 10;

struct node
{
	vector<vector<int>> a;
	int x;
};

int n;
set<string> vis;

bool judge(vector<vector<int>>& a)
{
	if (a[1].empty()) return 0;
	for (int i = 2; i <= n; i++)
	{
		if (a[i].empty()) return 0;
		if (a[i].back() < a[i - 1].back()) return 0;
	}
	return 1;
}

string get_id(vector<vector<int>>& a)
{
	string id = " ";
	for (int i = 1; i <= n; i++)
	{
		if (a[i].empty()) id += ' ';
		else for (auto& c : a[i]) id += c + '0';
		id += '-';
	}
	return id;
}

int bfs(vector<vector<int>> &v)
{
	string s;
	queue<node> q;
	q.push({ v, 0 });
	vis.insert(get_id(v));

	while (q.size())
	{
		vector<vector<int>> a = q.front().a;
		int x = q.front().x;
		q.pop();
		if (judge(a)) return x;

		for (int i = 1; i <= n; i++)
		{
			if (a[i].empty()) continue;
			if (a[i - 1].empty() || a[i - 1].back() > a[i].back())
			{
				a[i - 1].push_back(a[i].back());
				a[i].pop_back();
				s = get_id(a);
				if (!vis.count(s))
				{
					vis.insert(s);
					q.push({ a, x + 1 });
				}
				a[i].push_back(a[i - 1].back());
				a[i - 1].pop_back();
			}

			if (a[i + 1].empty() || a[i + 1].back() > a[i].back())
			{
				a[i + 1].push_back(a[i].back());
				a[i].pop_back();
				s = get_id(a);
				if (!vis.count(s))
				{
					vis.insert(s);
					q.push({ a, x + 1 });
				}
				a[i].push_back(a[i + 1].back());
				a[i + 1].pop_back();
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	while (cin >> n && n)
	{
		vector<vector<int>> v(N); string s = " ";
		v[0].push_back(-1e6), v[n + 1].push_back(-1e6);
		for (int i = 1; i <= n; i++)
		{
			int x; cin >> x;
			v[i].push_back(x);
		}
		int res = bfs(v); vis.clear();
		if (!~res) cout << "IMPOSSIBLE\n";
		else cout << res << '\n';
	}

	return 0;
}