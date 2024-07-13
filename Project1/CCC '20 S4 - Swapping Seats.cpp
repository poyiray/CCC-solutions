#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int na[2 * N], nb[2 * N], nc[2 * N], a, b, c, res = INT_MAX, sz;
char s[2 * N];

int get(int x, int y, int arr[])
{
	return arr[y] - arr[x - 1];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> s + 1; sz = strlen(s + 1);
	for (int i = 1; i <= sz; i++) s[i + sz] = s[i];
	for (int i = 1; i <= 2 * sz; i++)
	{
		na[i] = na[i - 1] + (s[i] == 'A');
		nb[i] = nb[i - 1] + (s[i] == 'B');
		nc[i] = nc[i - 1] + (s[i] == 'C');
	}
	a = na[sz], b = nb[sz], c = nc[sz];
	for (int i = 1; i <= sz; i++)
	{
		int temp_a = get(i, i + a - 1, na);
		int temp_b = get(i + a, i + a + b - 1, nb);
		int temp_c = min(get(i, i + a - 1, nb), get(i + a, i + a + b - 1, na));
		int temp = (a - temp_a) + (b - temp_b) - temp_c;
		res = min(res, temp);
	}
	for (int i = 1; i <= sz; i++)
	{
		int temp_a = get(i, i + a - 1, na);
		int temp_b = get(i + a, i + a + c - 1, nc);
		int temp_c = min(get(i, i + a - 1, nc), get(i + a, i + a + c - 1, na));
		int temp = (a - temp_a) + (c - temp_b) - temp_c;
		res = min(res, temp);
	}
	cout << res;

	return 0;
}