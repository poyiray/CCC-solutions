#include <bits/stdc++.h>
using namespace std;
int a = 1, b = 2, c = 0, d = 0;
long long cnt = 0;

void bf(int end)
{
	for (int i = 1; i <= end; i++)
	{
		d++;
		if (d == 10)
		{
			d = 0;
			c++;
		}
		if (c == 6)
		{
			c = 0;
			b++;
		}

		if (a == 1 && b > 2)
		{
			a = 0;
			b = 1;
		}
		if (b >= 10)
		{
			b = 0;
			a++;
		}

		int dif1 = a - b;
		int dif2 = b - c;
		int dif3 = c - d;
		if (a != 0)
		{
			if (dif1 == dif2 && dif1 == dif3)
			{
				cnt++;
			}
		}
		else
		{
			if (dif2 == dif3)
			{
				cnt++;
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	long long end;
	cin >> end;

	cnt = end / 720 * 31;
	bf(end % 720);

	cout << cnt;
	return 0;
}