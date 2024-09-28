#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, m, a, b, c, ed;
bool r[N][N], tmp[N][N], vis[10000000], dis[10000000];

void convert(int x)
{
	for (int i = m * n; i >= 1; i--)
		r[n - (int)ceil(i / (double)m) + 1][m - ((i - 1) % m + 1) + 1] = (1 << (i - 1)) & x;
}

int id()
{
	int x = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			x = x << 1 | r[i][j];
	return x;
}

void ck()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			tmp[i][j] = r[i][j];
			if (r[i][j])
			{
				if (r[i - 1][j - 1] + r[i - 1][j + 1] + r[i - 1][j]
					+ r[i][j - 1] + r[i][j + 1] + r[i + 1][j - 1] + r[i + 1][j + 1] + r[i + 1][j] < a) tmp[i][j] = 0;
				else if (r[i - 1][j - 1] + r[i - 1][j + 1] + r[i - 1][j]
					+ r[i][j - 1] + r[i][j + 1] + r[i + 1][j - 1] + r[i + 1][j + 1] + r[i + 1][j] > b) tmp[i][j] = 0;
			}
			else
			{
				if (r[i - 1][j - 1] + r[i - 1][j + 1] + r[i - 1][j]
					+ r[i][j - 1] + r[i][j + 1] + r[i + 1][j - 1] + r[i + 1][j + 1] + r[i + 1][j] > c) tmp[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			r[i][j] = tmp[i][j];
}

void god()
{
	int pre = id();
	while (1)
	{
		ck();
		int cur = id();
		if (vis[cur] || pre == cur) return;
		pre = cur;
		vis[cur] = 1;
	}
}

void bfs()
{
	queue<pair<int, int>> q;
	for (int i = 0; i <= (1 << (n * m)) - 1; i++) if (!vis[i]) q.push({i, 0});
	while (q.size())
	{
		int x = q.front().first, d = q.front().second; q.pop();
		convert(x);
		ck();
		int idx = id();
		if (d >= 100) { cout << -1 << '\n'; exit(0); }
		if (idx == ed) { cout << d + 1 << '\n'; exit(0); }
		q.push({ idx, d + 1 });
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m >> a >> b >> c;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char x; cin >> x;
			ed = ed << 1 | (x == '*');
		}
	}

	for (int i = (1 << (n * m)) - 1; i >= 0; i--)
	{
		convert(i);
		god();
	}
	if (!vis[ed])
	{
		cout << 0 << endl;
		return 0;
	}
	bfs();
	cout << -1 << endl;

	return 0;
}