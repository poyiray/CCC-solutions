#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int x, y;
	cin >> x >> y;

	if (x > 0 && y > 0)
	{
		cout << 1;
	}
	else if (x < 0 && y < 0)
	{
		cout << 3;
	}
	else if (x > 0 && y < 0)
	{
		cout << 4;
	}
	else
	{
		cout << 2;
	}

	return 0;
}