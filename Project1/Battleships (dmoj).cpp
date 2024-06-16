#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int N = 2e3 + 1;
int n, m, s, p[N], b[N];
bool a[N][N];
double res;

inline void prefix()
{
	for (int i = 1; i <= m; i++)
	{
		p[i] = p[i - 1] + b[i];
	}
	for (int i = s; i <= m; i++)
	{
		res += p[i] - p[i - s];
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char c; cin >> c;
			a[i][j] = c == 'X' ? 1 : 0;
		}
	}
	for (int j = 1; j <= m; j++)
	{
		for (int k = 1; k <= s; k++)
		{
			b[j] += a[k][j];
		}
	}
	prefix();

	for (int i = s + 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i - s][j]) b[j]--;
			if (a[i][j]) b[j]++;
		}
		prefix();
	}

	cout << fixed << setprecision(8) << res / ((n - s + 1) * (m - s + 1));

	return 0;
}