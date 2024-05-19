#include <bits/stdc++.h>
using namespace std;

int ta[1000];
int fa[1000];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	fa['a'] = fa['b'] = fa['c'] = 1;
	fa['d'] = fa['e'] = fa['f'] = 2;
	fa['g'] = fa['h'] = fa['i'] = 3;
	fa['j'] = fa['k'] = fa['l'] = 4;
	fa['m'] = fa['n'] = fa['o'] = 5;
	fa['p'] = fa['q'] = fa['r'] = fa['s'] = 6;
	fa['w'] = fa['x'] = fa['y'] = fa['z'] = 7;
	fa['t'] = fa['u'] = fa['v'] = 8;
	ta['a'] = ta['d'] = ta['g'] = ta['j'] = ta['m'] = ta['p'] = ta['t'] = ta['w'] = 1;
	ta['b'] = ta['e'] = ta['h'] = ta['k'] = ta['n'] = ta['q'] = ta['u'] = ta['x'] = 2;
	ta['c'] = ta['f'] = ta['i'] = ta['l'] = ta['o'] = ta['r'] = ta['v'] = ta['y'] = 3;
	ta['s'] = ta['z'] = 4;
	string s;
	while (cin >> s && s != "halt")
	{
		int res = 0;
		for(int i = 0; i < s.size(); i++)
		{
			int c = s[i];
			if (i && fa[s[i - 1]] == fa[c]) res += 2;
			res += ta[c];
		}
	}
	cout << 7;
	return 0;
}