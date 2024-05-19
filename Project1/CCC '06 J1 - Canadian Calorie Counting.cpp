#include <bits/stdc++.h>
using namespace std;

int arr[4][4] =
{
	461, 431, 420, 0,
	100, 57, 70, 0,
	130, 160, 118, 0,
	167, 266, 75, 0
};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

	int n, sum = 0;
	
	for (int i = 0; i < 4; i++)
	{
		cin >> n;
		sum += arr[i][n - 1];
	}

	cout << "Your total Calorie count is " << sum << ".";

	return 0;
}