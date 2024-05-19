#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int sum = n;
	int temp = n;
	for (int i = 1; i <= k; i++)
	{
		temp *= 10;
		sum += temp;
	}
	cout << sum;

	return 0;
}