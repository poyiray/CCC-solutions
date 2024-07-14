// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

int n, v1, v2, v3, c1, c2, c3;

int main()
{
	cin >> n >> v1 >> c1 >> v2 >> c2 >> v3 >> c3;

	int a = ceil(n * 1.0 / v1) * c1;
	int b = ceil(n * 1.0 / v2) * c2;
	int c = ceil(n * 1.0 / v3) * c3;
	cout << min({ a,b,c });

	return 0;
}