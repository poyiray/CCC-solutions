#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	string s;
	while (cin >> s)
	{
		if (s == "quit!")
		{
			break;
		}
			

		if (s.size() > 4 && s.substr(s.size() - 2, 2) == "or")
		{
			s.pop_back();
			s.pop_back();
			if (s.back() != 'o')
				s += "our";
			else
				s += "or";
		}
		cout << s << endl;
	}

	return 0;
}