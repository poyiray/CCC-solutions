#include <bits/stdc++.h>
using namespace std;

struct node
{
	int res, move;
};

const int N = 110;
int r, c, pr, pc, kr, kc, dis[N][N];
node mem[N][N];

int dx[] = { 2,2,1,1,-1,-1,-2,-2 };
int dy[] = { 1,-1,2,-2,2,-2,1,-1 };

//细节: 如果骑士能够到达一个点 那么他在 n + 2x 次都可以到达 (因为他可以绕个圈原地踏步)
node dfs(int n, int x, int y, int px, int py)
{
	
	if (n >= r - pr) return {1, n};
	if (x < 1 || x > r || y < 1 || y > c) return { 1, n };
	if (dis[px][py] + 1 >= dis[x][y]) return mem[x][y];
	dis[x][y] = dis[px][py] + 1;
	if (y == pc && x >= pr + n)
	{
		int d = x - pr - n;
		if (d % 2 == 0)
		{
			if (x == r) return { 1,-1 };
			return { 3, n + d };
		}
		else return { 2, n + d - 1 };
	}

	node a = { 0,0 };
	for (int i = 0; i < 8; i++)
	{
		if (x + dx[i] == px && x + dy[i] == py) continue;
		node temp = dfs(n + 1, x + dx[i], y + dy[i], x, y);

		if (temp.res > a.res) a = temp;
		else if (temp.res == a.res && temp.move < a.move) a.move = temp.move;
	}
	return mem[x][y] = a;
}

void solve()
{
	cin >> r >> c >> pr >> pc >> kr >> kc;
	memset(dis, 0x3f, sizeof dis);
	memset(mem, 0, sizeof mem);
	dis[0][0] = 0;
	node a = dfs(0, kr, kc, 0, 0);
	if (a.res == 1) cout << "Loss in " << r - pr - 1 << " knight move(s).";
	else if (a.res == 2) cout << "Stalemate in " << a.move << " knight move(s).";
	else cout << "Win in " << a.move << " knight move(s).";
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int _; cin >> _;
	while (_--) solve();

	return 0;
}