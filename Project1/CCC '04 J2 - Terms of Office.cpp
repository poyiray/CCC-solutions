#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	int x, y;
	cin >> x >> y;
	cout << "All positions change in year " << x << endl;

	for (int i = 1; i <= y - x; i++)
	{
		if (i % 4 + i % 2 + i % 3 + i % 5 == 0)
		{
			cout << "All positions change in year " << x + i << endl;
		}
	}

	return 0;
}