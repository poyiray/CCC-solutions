#include <bits/stdc++.h>
using namespace std;

int res, n, r, f;
int main()
{
	cin >> n;
	while (n != 1) //Ì«tmÉñÆæÁË
	{
		r = sqrt(n); f = 2;
		while (f <= r && n % f != 0) f++;
		if (n % f == 0)
		{
			int x = n / f;
			n -= x;
			res += n / x;
		}
		else
		{
			n--;
			res += n;
		}
	}
	cout << res;
	return 0;
}