#include <iostream>
#include <queue>
#include <windows.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 26;
int g[N][N], gas[N][N];
int n;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void dj()
{
	fill(gas[0], gas[0] + N * N, INF);
	priority_queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {0,0} });
	gas[0][0] = 0;
	while (q.size())
	{
		auto u = q.top().second; q.pop();
		for (int i = 0; i < 4; i++)
		{
			int a = u.first + dx[i], b = u.second + dy[i];
			if (a < 0 || a >= n || b < 0 || b >= n) continue;
			if (abs(g[a][b] - g[u.first][u.second]) > 2) continue;
			if (g[a][b] > g[0][0] || g[u.first][u.second] > g[0][0])
			{
				if (gas[u.first][u.second] + 1 < gas[a][b])
				{
					gas[a][b] = gas[u.first][u.second] + 1;
					q.push({ -gas[a][b], {a,b} });
				}
			}
			else
			{
				if (gas[u.first][u.second] < gas[a][b])
				{
					gas[a][b] = gas[u.first][u.second];
					q.push({ -gas[a][b], {a,b} });
				}
			}
		}
	}
}

int main()
{
	int _; cin >> _;
	while (_--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> g[i][j];
		dj();
		if (gas[n - 1][n - 1] != INF) cout << gas[n - 1][n - 1] << '\n';
		else cout << "CANNOT MAKE THE TRIP\n";
		if (_) cout << '\n';
	}

	return 0;
}