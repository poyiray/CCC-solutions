#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#include <vector>
using namespace std;

char *p1, *p2, buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int rd()
{
	int x = 0; char ch = nc();
	while (ch < 48 || ch>57) ch = nc();
	while (ch >= 48 && ch <= 57) x = x * 10 + ch - 48, ch = nc();
	return x;
}

const int N = 3e3 + 10;
int a[N][N][2], n, k;
long long res;

int query(int i, int j, int q)
{
	int h = log2(q), u = h & 1;
	int x = max({ a[i][j][u],a[i + k - (1 << h)][j][u],a[i + k - (1 << h)][j + k - (1 << h)][u] });
	if (h <= 1) return x;
	int y = max({ a[i + ((k - (1 << h)) >> 1)][j][u],a[i + ((k - (1 << h)) >> 1)][j + ((k - (1 << h)) >> 1)][u],a[i + k - (1 << h)][j + ((k - (1 << h)) >> 1)][u] });
	int maxn = max(x, y);
	return maxn;
}

void sol()
{
	n = rd(), k = rd();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			a[i][j][0] = rd();

	for (int h = 1; h <= log2(k); h++)
	{
		int u = h & 1, v = u ^ 1;
		for (int i = 1; i + (1 << h) - 1 <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				int x = max({ a[i][j][v],a[i + (1 << h - 1)][j][v],a[i + (1 << h - 1)][j + (1 << h - 1)][v] });
				int y = 0;
				if (h > 1) y = max({ a[i + (1 << h - 2)][j][v],a[i + (1 << h - 2)][j + (1 << h - 2)][v],a[i + (1 << h - 1)][j + (1 << h - 2)][v] });
				a[i][j][u] = max(x, y);
			}
		}
	}

	for (int i = 1; i + k - 1 <= n; i++)
		for (int j = 1; j <= i; j++)
			res += query(i, j, k);

	cout << res;
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif

	sol();

	return 0;
}