#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n, m, j[N], res;

int tonum(char c)
{
	int num;
	if (c == 'M') num = 2;
	else if (c == 'L') num = 3;
	else num = 1;
	return num;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> m >> n;
	for(int i = 1; i <= m; i++)
	{
		char c; cin >> c;
		j[i] = tonum(c);
	}
	while (n--)
	{
		char c; int a; cin >> c >> a;
		if (j[a] >= tonum(c) && j[a] != -1) res++, j[a] = -1;
	}
	cout << res;
	return 0;
}