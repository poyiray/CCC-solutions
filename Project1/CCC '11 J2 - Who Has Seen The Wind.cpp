#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	int h, t;
	cin >> h >> t;

	for (int i = 1; i <= t; i++)
	{
		int a = (-6 * pow(i, 4)) + (h * pow(i, 3)) + (2 * pow(i, 2)) + i;
		if (a <= 0)
		{
			cout << "The balloon first touches ground at hour:" << endl << i;
			return 0;
		}
	}
	cout << "The balloon does not touch ground in the given time.";
	return 0;
}