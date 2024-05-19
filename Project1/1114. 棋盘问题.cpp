#include <iostream>
using namespace std;

int n, k, res;
char g[11][11];
bool st[10];

void dfs(int x, int t)
{
	if (t == k)
	{
		res++;
		return;
	}

	if (x >= n) return;

	for (int i = 0; i < n; i++)
	{
		if (g[x][i] == '#' && !st[i])
		{
			st[i] = true;
			dfs(x + 1, t + 1);
			st[i] = false;
		}
	}
	dfs(x + 1, t);
}

int main()
{
	while (cin >> n >> k)
	{
		if (n == -1 && k == -1)
			break;
		for (int i = 0; i < n; i++)
			cin >> g[i];

		dfs(0, 0);
		cout << res << endl;
		res = 0;
	}

	return 0;
}