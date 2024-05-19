#include <bits/stdc++.h>
using namespace std;

long long l = 0, r = 2e9 + 1, m;

int main()
{
	//freopen("in.txt", "r", stdin);
	char s[12];
	while(l + 1 != r)
	{
		m = (l + r) >> 1;
		cout << m << endl;
		cin >> s;
		if (s[0] == 'S') l = m;
		else if (s[0] == 'F') r = m;
		else break;
	}
	return 0;
}