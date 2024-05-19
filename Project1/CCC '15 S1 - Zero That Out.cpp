#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	stack<int> s; int n, res = 0; cin >> n;
	while (n--)
	{
		int v; cin >> v;
		if (!v && s.size()) s.pop();
		else s.push(v);
	}
	while (s.size())
		res += s.top(), s.pop();
	cout << res;
	return 0;
}