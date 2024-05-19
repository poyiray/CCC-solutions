#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
unordered_map<int, set<int>> members;
char q;
int x, y;
int vis[60];
void add(int u, int v)
{
	members[u].insert(v);
	members[v].insert(u);
}

void bfs()
{
	memset(vis, -1, sizeof vis);
	queue<int> q;
	q.push(x);
	vis[x] = 0;

	while (q.size())
	{
		auto t = q.front(); q.pop();
		for (auto val : members[t])
		{
			if (vis[val] >= 0) continue;
			vis[val] = vis[t] + 1;
			q.push(val);
			if (val == y)
			{
				cout << vis[val] << endl;
				return;
			}
		}
	}
	cout << "Not connected" << endl;;
}

int main()
{
	add(1, 6), add(6, 2), add(6, 7), add(6, 4), add(6, 5), add(6, 3);
	add(4, 5), add(5, 3), add(3, 4), add(3, 15);
	add(15, 13), add(13, 12), add(13, 14), add(12, 11), add(11, 10), add(12, 9), add(9, 8), add(8, 7), add(9, 10);
	add(16, 18), add(18, 17), add(17, 16);

	while (cin >> q)
	{
		int res = 0;
		if (q == 'q') break;
		cin >> x;
		if (q != 'n' && q != 'f') cin >> y;
		switch (q)
		{
		case 'i':
			add(x, y);
			break;
		case 'd':
			members[x].erase(y);
			members[y].erase(x);
			break;
		case 'n':
			cout << members[x].size() << endl;
			break;
		case 'f':
			memset(vis, 0, sizeof vis);
			vis[x] = 1;
			res = 0;
			for (auto val : members[x])
			{
				for (auto to : members[val])
				{
					if (members[x].count(to)) continue;
					if (vis[to]) continue;
					vis[to] = 1;
					res++;
				}
			}
			cout << res << endl;
			break;
		case 's':
			bfs();
			break;
		}
	}

	return 0;
}