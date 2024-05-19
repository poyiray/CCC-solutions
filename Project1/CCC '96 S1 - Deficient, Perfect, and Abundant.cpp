#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
	cin >> n;
	while (n--)
	{
		int res = 0;
		int num; cin >> num;
		for (int i = 1; i <= num / 2; i++)
		{
			if (!(num % i)) res += i;
		}
		cout << num;
		if (res > num) cout << " is an abundant number.";
		else if (res < num) cout << " is a deficient number.";
		else cout << " is a perfect number.";
		cout << '\n';
	}


	return 0;
}