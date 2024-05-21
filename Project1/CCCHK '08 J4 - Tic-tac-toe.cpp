#include <bits/stdc++.h>
using namespace std;

int n;
string s;

bool win(char c)
{
	if (s[0] == c && s[1] == c && s[2] == c) return 1;
	else if (s[0] == c && s[4] == c && s[8] == c) return 1;
	else if (s[2] == c && s[4] == c && s[6] == c) return 1;
	else if (s[3] == c && s[4] == c && s[5] == c) return 1;
	else if (s[6] == c && s[7] == c && s[8] == c) return 1;
	else if (s[0] == c && s[3] == c && s[6] == c) return 1;
	else if (s[1] == c && s[4] == c && s[7] == c) return 1;
	else if (s[2] == c && s[5] == c && s[8] == c) return 1;
	return 0;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	while(n--)
	{
		int x, o; x = o = 0;
		cin >> s;
		for (auto& c : s)
		{
			if (c == 'O') o++;
			else if (c == 'X') x++;
		}
		if (o == 0 && x == 0) cout << "yes";
		else if (o > x || o < x - 1) cout << "no";
		else if (o >= x && win('X')) cout << "no";
		else if (x > o && win('O')) cout << "no";
		else cout << "yes";
		cout << '\n';
	}

	return 0;
}