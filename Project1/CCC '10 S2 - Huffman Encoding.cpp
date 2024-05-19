#include <bits/stdc++.h>
using namespace std;

int n;
string code;
unordered_map<string, char> m;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	while (n--)
	{
		char c; string s; cin >> c >> s;
		m[s] = c;
	}
	cin >> code;
	int i = 0;
	while(i < code.size())
	{
		for (int j = 1; j < code.size() - i + 1; j++)
		{
			string t = code.substr(i, j);
			if (m.find(t) != m.end())
			{
				cout << m[t];
				i += j;
				break;
			}
		}
	}

	return 0;
}