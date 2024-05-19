#include <bits/stdc++.h>
#include <regex>
using namespace std;
int n;
int main()
{
	cin >> n; getchar();
	while (n--)
	{
		string s; getline(cin, s);
		smatch res;
		regex pat("\\b\\w{4}\\b");
		cout << regex_replace(s, pat, "****") << '\n';
	}
	return 0;
}