#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	unordered_map<char, int> m1, m2;
	string s1, s2; cin >> s1 >> s2;
	for (auto& c : s1) m1[c]++;
	for (auto& c : s2) m2[c]++;
	for (auto& v : m1)
	{
		int dif = v.second - m2[v.first];
		if (dif == 0) continue;
		if (dif < 0 || (dif > m2['*']))
		{
			cout << 'N'; return 0;
		}
		else
		{
			m2['*'] -= dif;
		}
	}
	cout << "A";
	return 0;
}