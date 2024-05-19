#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int p[N], n, m;
set<int> s;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) s.insert(i);
	for(int i = 1; i <= m; i++)
	{
		int g; cin >> g;
		auto it = s.upper_bound(g);
		if (it == s.begin() || *(--it) > g) 
		{ 
			cout << i - 1 << '\n'; 
			return 0;
		}
		s.erase(*it);
	}
	cout << m;
	return 0;
}