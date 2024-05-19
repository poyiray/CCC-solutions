#include <iostream>
using namespace std;

int main()
{
	int p, n, r;
	cin >> p >> n >> r;
	int sum = n, cnt = 1;
	int temp = n * r;
	while (sum < p)
	{
		sum = sum + temp;
		temp *= r;
		if(sum <= p)
			cnt++;
	}
	cout << cnt;

	return 0;
}