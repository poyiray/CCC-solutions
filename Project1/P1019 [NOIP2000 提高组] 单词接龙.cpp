#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
string words[30];
int used[30];
int g[30][30];
int res;

void dfs(string dragon, int x)
{
	res = max((int)dragon.size(), res);
	used[x]++;
	for (int i = 0; i < n; i++)
	{
		if (g[x][i] && used[i] < 2)
		{
			dfs(dragon + words[i].substr(g[x][i]), i);
		}
	}
	used[x]--;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> words[i];

	char start; cin >> start;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			string a = words[i], b = words[j];
			for (int k = 1; k < min(a.size(), b.size()); k++)
			{
				if (a.substr(a.size() - k) == b.substr(0, k))
				{
					g[i][j] = k;
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (words[i][0] == start)
			dfs(words[i], i);
	}
	cout << res << endl;
	return 0;
}