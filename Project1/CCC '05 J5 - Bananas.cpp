#include <bits/stdc++.h>
using namespace std;

//真几把难
//A word = A || B + monkey word + S
//monkey word = A word + N + monkey word || A word

bool a(string s), b(string s);

bool a(string s)
{
	if (b(s)) return 1; //如何这整个字符串都是一个monkey word 那就没必要继续了

	bool f = false;
	for (int i = 1; i < s.size() - 1; i++)
	{
		if (a(s.substr(0, i)) && s[i] == 'N' && b(s.substr(i + 1, s.size() - i - 1)))
			f = true;
	}
	return f;
}
bool b(string s)
{
	if (s == "A") return 1;
	else if (s.size() >= 3)
	{
		if (s[0] == 'B' && a(s.substr(1, s.size() - 2)) && s[s.size() - 1] == 'S') return 1;
		else return 0;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	string s;
	while (cin >> s && s != "X")
	{
		if (a(s)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}


