#include <bits/stdc++.h>
using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
double a[N], res = INF;
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 1; i < n - 1; i++)
	{
		double temp = abs(a[i] - ((a[i] + a[i - 1]) / 2)) + abs(a[i] - ((a[i] + a[i + 1]) / 2));
		res = min(temp, res);
	}
	cout << fixed << setprecision(1) << res;
	return 0;
}