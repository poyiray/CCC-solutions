#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 1e3;
int head[N], to[N], nxt[N], cnt; //Á´Ê½ÏòÇ°ÐÇ

void add(int u, int v)
{
	u -= 'A', v -= 'A';
	nxt[++cnt] = head[u];
	head[u] = cnt;
	to[cnt] = v;
}

int res, dfn[N], low[N], time;
void tarjan(int x, int root)
{
	dfn[x] = low[x] = ++time;
	for (int i = head[x]; i; i = nxt[i])
	{
		int y = to[i];
		if (y == root) continue;
		if (!dfn[y])
		{
			tarjan(y, x);
			low[x] = min(low[x], low[y]);
			if (low[y] > dfn[x])
			{
				res++;
				cout << char(y + 'A') << char(x + 'A') << endl;
			}
		}
		else
		{
			low[x] = min(low[x], dfn[y]);
		}
	}
}

int main()
{
	string s;
	while (cin >> s)
	{
		if (s == "**") break;
		add(s[0], s[1]);
		add(s[1], s[0]);
	}

	tarjan(1, 1);
	cout << "There are " << res << " disconnecting roads." << endl;

	return 0;
}