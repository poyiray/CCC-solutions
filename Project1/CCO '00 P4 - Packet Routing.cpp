#include <iostream>
using namespace std;
inline int read()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}
const int N = 105;
const int INF = 0x3f3f3f3f;
int g[N][N], dis[N][N];
int main()
{
	int n = read(), m = read(), p = read();
	for (int i = 1; i <= n; i++)
		fill(g[i], g[i] + n + 1, INF);
	while (m--)
	{
		int u = read(), v = read(), w = read();
		g[u][v] = w;
		g[v][u] = w;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dis[i][j] = g[i][j];
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dis[i][k] + dis[k][j] < dis[i][j])
					dis[i][j] = dis[i][k] + dis[k][j];
	while (p--)
	{
		int u = read(), v = read();
		cout << dis[u][v] << '\n';
	}
}