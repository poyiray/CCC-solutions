#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int c, r, x, y, px = 0, py = 0;
	cin >> c >> r;

	while (cin >> x >> y)
	{
		if (x == 0 && y == 0)
			break;
		px += x;
		py += y;

		if (px > c)
			px = c;
		else if (px < 0)
			px = 0;

		if (py >= r)
			py = r;
		else if (py < 0)
			py = 0;
		cout << px << " " << py << endl;
	}

	return 0;
}