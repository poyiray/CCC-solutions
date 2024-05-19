#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int m, d;
	cin >> m >> d;
	if (m < 2)
	{
		cout << "Before";
	}
	else if (m > 2)
	{
		cout << "After";
	}
	else
	{
		if (d > 18)
		{
			cout << "After";
		}
		else if (d < 18)
		{
			cout << "Before";
		}
		else
		{
			cout << "Special";
		}
	}

	return 0;
}