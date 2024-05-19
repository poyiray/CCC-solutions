#include <bits/stdc++.h>
using namespace std;
int sad, h;
int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	string s;
	getline(cin, s);
	
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ':')
		{
			if (s[i + 2] == ')')
			{
				h++;
			}
			else if (s[i + 2] == '(')
			{
				sad++;
			}
		}
	}

	if (sad == 0 && h == 0)
	{
		cout << "none";
		
	}
	else if (sad > h)
	{
		cout << "sad";
	}
	else if (h > sad)
	{
		cout << "happy";
	}
	else
	{
		cout << "unsure";
	}

	return 0;
}