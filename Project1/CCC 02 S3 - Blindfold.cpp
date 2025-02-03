#include <bits/stdc++.h>
using namespace std;

const int N = 400, M = 90;
struct node
{
	int x, y;
	bool operator<(const node& n) const
	{
		if (x == n.x) return y < n.y;
		return x < n.x;
	}
};
int r, c, m, vx, vy, wl, wr, wu, wd;
set<node> pos;
char a[N][M], q[30010];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0,-1 };

int mod(int a, int b) { return (a % b + b) % b; }

void init(int d)
{
	pos.clear();
	vx = vy = 0;
	wl = wr = wu = wd = 0;
	for (int i = 1; i <= m; i++)
	{
		if (q[i] == 'F')
		{
			vx += dx[d];
			vy += dy[d];
			wl = min(wl, vy);
			wr = max(wr, vy);
			wu = min(wu, vx);
			wd = max(wd, vx);
			pos.insert({ vx,vy });
		}
		else
		{
			d += (q[i] == 'L' ? -1 : 1);
			d = mod(d, 4);
		}
	}
}

void solve()
{
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (a[i][j] == 'X' || a[vx + i][vy + j] == 'X') continue;
			if (wl + j <= 0 || wr + j > c) continue;
			if (wu + i <= 0 || wd + i > r) continue;
			int f = false;
			for(auto [x,y] : pos)
			{
				x += i, y += j;
				if (x <= 0 || x > r || y <= 0 || y > c || a[x][y] == 'X') { f = true; break; }
			}
			if (!f) a[vx + i][vy + j] = '*';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> r >> c;
	for (int i = 1; i <= r; i++) cin >> a[i] + 1;
	cin >> m;
	for (int i = 1; i <= m; i++) cin >> q[i];

	for (int i = 0; i < 4; i++)
	{
		init(i);
		solve();
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
			cout << a[i][j];
		cout << '\n';
	}
	
	return 0;
}