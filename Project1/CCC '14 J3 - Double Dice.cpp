#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int sum1 = 100, sum2 = 100;
	for (int i = 0; i < n; i++)
	{
		int a, b; cin >> a >> b;
		if (a == b)
			continue;
		a > b ? sum2 -= a : sum1 -= b;
	}
	cout << sum1 << "\n" << sum2;

	return 0;
}