#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	string s;
	getline(cin, s);

	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i];
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			continue;
		int l = 0, r = 0;

		for (int j = s[i] + 1; j <= 'z' + 1; j++)
		{
			r++;
			if (j >= 'z')
			{
				r = 100;
				break;
			}
			if (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u')
				break;
		}
		for (int j = s[i] - 1; j >= 'a'; j--)
		{
			l++;
			if (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u')
				break;
		}

		if (l <= r)
			cout << (char)(s[i] - l);
		else
			cout << (char)(s[i] + r);

		if (s[i] == 'z')
		{
			cout << "z";
		}
		else if (r == 1)
		{
			cout << (char)(s[i] + 2);
		}
		else
		{
			cout << (char)(s[i] + 1);
		}
	}

	return 0;
}