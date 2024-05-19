#include <iostream>
using namespace std;

const int N = 33, M = 5280;
int n, m, club[N], mem[M][M], res = 0x3f3f3f3f;

//x -- 击打的次数, dis -- 前进了多少
void dfs(int x, int dis)
{
	if (dis > m || mem[x][dis]) return;
	if (dis == m && x < res) res = x;
	mem[x][dis] = true;
	for (int i = 0; i < n; i++) dfs(x + 1, dis + club[i]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> m >> n;
	for (int i = 0; i < n; i++) cin >> club[i];

	for (int i = 0; i < n; i++) dfs(1, club[i]);
	if (res == 0x3f3f3f3f) cout << "Roberta acknowledges defeat.";
	else cout << "Roberta wins in " << res << " strokes.";
	return 0;
}