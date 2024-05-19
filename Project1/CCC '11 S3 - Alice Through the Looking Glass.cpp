#include <bits/stdc++.h>
using namespace std;
bool dfs(int lvl, int x, int y)
{
	int area = (int)pow(5, lvl - 1);
	int zx = x / area, zy = y / area;
	if (zx < 1 || zx > 3 || zy > 2 || (zy == 2 && (zx == 1 || zx == 3))) return false;
	if ((zy == 0 && (zx == 1 || zx == 2 || zx == 3)) || (zy == 1 && zx == 2)) return true;
	if (lvl == 1) return false;
	return dfs(lvl - 1, x % area, y % area);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	while (n--)
	{
		int lvl, x, y; cin >> lvl >> x >> y;
		if (dfs(lvl, x, y)) cout << "crystal\n";
		else cout << "empty\n";
	}
	return 0;
}