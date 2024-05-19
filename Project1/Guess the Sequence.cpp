#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cout << j << endl;
			cin >> s;
			if (s[0] == 'Y') { cout << j << endl; break; }
		}
		cin >> s;
		if (s[0] == 'D') break;
	}

	return 0;
}