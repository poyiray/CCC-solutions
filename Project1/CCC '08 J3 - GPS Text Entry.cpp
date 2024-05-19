#include <bits/stdc++.h>
using namespace std;

unordered_map<char, pair<int, int>> m;
int res;
char cur;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cur = 'A'; string s; getline(cin, s);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			m[i * 6 + j + 'A'] = { i, j };
		}
	}
	m[' '] = { 4, 2 };
	m['-'] = { 4, 3 };
	m['.'] = { 4, 4 };
	for (auto& c : s)
	{
		res += abs(m[cur].first - m[c].first) + abs(m[cur].second - m[c].second);
		cur = c;
	}
	res += abs(m[cur].first - 4) + abs(m[cur].second - 5);
	cout << res;
	return 0;
}