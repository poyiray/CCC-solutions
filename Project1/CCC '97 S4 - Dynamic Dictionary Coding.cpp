#include <bits/stdc++.h>
using namespace std;

map<string, int> m;
vector<string> txt;
int n;

int main()
{
	//freopen("out.txt", "w", stdout);
	cin >> n; getchar();
	while (n--)
	{
		string s; int cnt = 1, idx = 0;
		while (getline(cin, s) && s.size())
		{
			s += ' ';
			string t;
			for (auto& c : s)
			{
				if (c == ' ')
				{
					txt.push_back(t);
					t.clear();
				}
				else t += c;
			}
			for (; idx < txt.size(); idx++)
			{
				string v = txt[idx];
				if (m.find(v) == m.end())
				{
					m[v] = cnt++;
					cout << v;
				}
				else cout << m[v];
				if (idx != txt.size() - 1) cout << ' ';
				else cout << '\n';
			}
			//cout << '\n';
		}
		m.clear();
		txt.clear();
		if (n) cout << '\n';
	}

	return 0;
}