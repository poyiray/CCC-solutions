#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool g[110][110];
int dis[110];
int n;
void bfs()
{
	memset(dis, -1, sizeof dis);
	queue<int> q;
	q.push(1);
	dis[1] = 0;

	while (q.size())
	{
		auto t = q.front(); q.pop();
		for (int i = 1; i <= n; i++)
		{
			if (!g[t][i] || dis[i] >= 0) continue;
			dis[i] = dis[t] + 1;
			q.push(i);
			if (i == n)
			{
				cout << dis[i] << endl;
				return;
			}
		}
	}

}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> g[i][j];

	bfs();

	return 0;
}