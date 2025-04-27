#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int a[N][N], level, width, loc;
struct rec
{
	int lx, ly, rx, ry;
	bool ck()
	{
		if (lx < 0 || rx > width || ry > width || ly < 1) return 1;
		return 0;
	}
};
void print()
{
	for (int i = width; i >= 0; i--)
	{
		for (int j = 1; j <= width; j++)
		{
			if (a[i][j]) cout << "■";
			else cout << "□";
		}
		cout << '\n';
	}
}
void dfs(int x, rec r)
{
	if (x > level || r.ck()) return;
	int dis = max((r.ry - r.ly + 1) / 3, (r.rx - r.lx + 1) / 3);
	for (int i = r.lx; i <= r.rx; i++)
	{
		for (int j = r.ly; j <= r.ry; j++)
		{
			a[i][j] = 1;
		}
	}
	if (!dis) return;
	if (r.ry - r.ly + 1 >= 3)
	{
		dfs(x + 1, { r.rx + 1, r.ly + dis, r.rx + dis, r.ry - dis }); // up
		dfs(x + 1, { r.lx - dis, r.ly + dis, r.lx - 1, r.ry - dis }); // down

		dfs(x + 1, { r.lx, r.ly, r.lx, r.ly + dis - 1 });
		dfs(x + 1, { r.lx, r.ry - dis + 1, r.lx, r.ry });
		dfs(x + 1, { r.rx, r.ly, r.rx, r.ly + dis - 1 });
		dfs(x + 1, { r.rx, r.ry - dis + 1, r.rx, r.ry });
	}
	if (r.rx - r.lx + 1 >= 3)
	{
		dfs(x + 1, { r.lx + dis, r.ly - dis, r.rx - dis, r.ly - 1 }); // left
		dfs(x + 1, { r.lx + dis, r.ry + 1, r.rx - dis, r.ry + dis }); // right

		dfs(x + 1, { r.lx, r.ly, r.lx + dis - 1, r.ly });
		dfs(x + 1, { r.rx - dis + 1, r.ly, r.rx, r.ly });
		dfs(x + 1, { r.lx, r.ry, r.lx + dis - 1, r.ry });
		dfs(x + 1, { r.rx - dis + 1, r.ry, r.rx, r.ry });
	}
}

int main()
{
	freopen("out.txt", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> level >> width >> loc;
	dfs(0, { 0, 1, 0, width });
	print();

	for (int i = 1; i <= width; i++)
	{
		if (!a[i][loc + 1])
		{
			if (a[i - 1][loc] || a[i - 1][loc + 1] || a[i][loc]) cout << i << " ";
		}
		else
		{
			if (!a[i - 1][loc] || !a[i - 1][loc + 1] || !a[i][loc]) cout << i << " ";
		}
	}
	return 0;
}