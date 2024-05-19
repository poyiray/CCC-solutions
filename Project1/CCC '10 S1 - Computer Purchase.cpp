#include <bits/stdc++.h>
using namespace std;

multiset<pair<int, string>> pc;
int n;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n; if (!n) return 0;
	while (n--)
	{
		string name; int r, s, d; cin >> name >> r >> s >> d;
		pc.insert({ -(2 * r + 3 * s + d), name });
	}
	cout << (*pc.begin()).second << '\n' << (*++pc.begin()).second;

	return 0;
}