#include <bits/stdc++.h>
using namespace std;

int n, y, m, d;
int qwq(int y, int m, int d)
{
	return y * 365 + m * 30 + d;
}

int main()
{
	int cur = 2007 * 365 + 60 + 27;
	int et = 18 * 365;
	cin >> n;
	while (n--)
	{
		cin >> y >> m >> d;
		if (cur - qwq(y, m, d) >= et) cout << "Yes";
		else cout << "No";
		cout << '\n';
	}

	return 0;
}