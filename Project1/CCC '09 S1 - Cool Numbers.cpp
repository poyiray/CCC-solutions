#include <bits/stdc++.h>
using namespace std;

int x, y, res;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> x >> y;
	int cube = (int)pow(x, 1.0 / 3);
	int c = pow(cube, 3);
	while (c <= y)
	{
		if (c >= x)
		{
			int square = (int)sqrt(c);
			int s = pow(square, 2);
			if (s == c) res++;
		}
		cube++;
		c = pow(cube, 3);
	}
	cout << res;

	return 0;
}