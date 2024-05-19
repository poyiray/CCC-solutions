#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[100];
int res;
int t;

void dfs(int x, int start, int sum)
{
	if (x > k)
	{
		if (sum == n)
		{
			for (int i = 1; i <= k; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			res++;
		}
		return;
	}

	for (int i = start; sum + (k - x + 1) * i <= n; i++)
	{
		arr[x] = i;
		dfs(x + 1, i, sum + i);
	}
}

int main()
{
	cin >> n >> k;
	t = n / k;

	for (int i = 1; i <= t; i++)
		dfs(2, i, i);
	cout << res << endl;

	return 0;
}