#include <bits/stdc++.h>
using namespace std;

int T, n, ans;

int res[7], score[5];
int game[][2] = { {1,2},{1,3},{1,4},{2,3},{2,4},{3,4} };

bool win()
{
	memset(score, 0, sizeof score);
	for (int i = 0; i < 6; i++)
	{
		if (res[i] == 1) score[game[i][0]] += 3;
		else if (res[i] == 2) score[game[i][1]] += 3;
		else score[game[i][1]]++, score[game[i][0]]++;
	}
	int num = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (i == T) continue;
		num = max(num, score[i]);
	}
	return num < score[T] ? 1 : 0;
}

void dfs(int x) // x - game played
{
	if (x == 6)
	{
		if (win()) ans++;
		return;
	}
	if (res[x]) { dfs(x + 1); return; }
	res[x] = 1;
	dfs(x + 1);

	res[x] = 2;
	dfs(x + 1);

	res[x] = 3;
	dfs(x + 1);

	res[x] = 0;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> T >> n;
	while (n--)
	{
		int x, y, a, b, t; cin >> x >> y >> a >> b;
		if (a > b) t = 1; // win
		else if (a < b) t = 2; // loss
		else t = 3; // tie
		for (int i = 0; i < 6; i++)
			if (x == game[i][0] && y == game[i][1]) res[i] = t; // 查找对应的回合
			// 插入已知的结果
	}
	dfs(0);
	cout << ans;
	return 0;
}