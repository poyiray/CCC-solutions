#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
string a[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	string s;
	while (getline(cin, s) && s[0] != '0')
	{
		int cnt = 0;
		for (auto& c : s) if (c != ' ') a[++cnt] = c;

		for (int i = cnt; i >= 1; i--)
		{
			if (a[i] != "-" && a[i] != "+") continue;
			int next = i + a[i + 1].size() + 1;
			a[next] += a[i];
			a[i] = a[i + 1] + a[next];
		}
		for (auto& c : a[1])
		{
			cout << c << " ";
		}
		cout << '\n';
	}


	return 0;
}