#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	int m, n, sum = 0;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (i + j == 10)
				sum++;

	cout << "There " << (sum == 1 ? "is " : "are ") << sum << (sum == 1? " way" : " ways") << " to get the sum 10.";
	

	return 0;
}