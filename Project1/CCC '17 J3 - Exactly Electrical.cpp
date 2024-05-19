#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int a, b, c, d, power;
	cin >> a >> b >> c >> d >> power;

	int dis = abs(a - c) + abs(b - d);
	if (dis > power || abs(dis - power) % 2 != 0)
	{
		cout << "N";
	}
	else if (abs(power - dis) % 2 == 0)
	{
		cout << "Y";
	}

	return 0;
}