#include <bits/stdc++.h>
using namespace std;

map<int, int> num;
map<int, string> name;
int mx, res = INT_MAX;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int _; cin >> _;
	while (_--)
	{
		string s; int n; cin >> s >> n;
		name[n] = s;
	}
	cin >> _;
	while (_--)
	{
		int n; cin >> n;
		num[n]++;
		mx = max(mx, num[n]);
	}

	for (auto& v : num)
	{
		if (v.second == mx)
		{
			res = min(res, v.first);
		}
	}
	cout << name[res];

	return 0;
}