#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926
const int N = 1e3 + 10;
double x, y, n, m, q, len;
int cnt = 0;

bool ck()
{
	if (y == 0 || y == n)
	{
		if (x <= 5 || x >= m - 5) return 0;
	}
	if (x == 0 || x == m)
	{
		if (y <= 5 || y >= n - 5) return 0;
	}
	return 1;
}

int main()
{
	cin >> m >> n >> x >> q;
	

	return 0;
}