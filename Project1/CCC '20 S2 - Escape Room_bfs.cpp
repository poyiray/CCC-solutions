#include <queue>
#include <iostream>
#include <unordered_map>
using namespace std;
int r, c;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	queue<int> q;
	cin >> r >> c;
	vector<vector<int>> g(r + 2, vector<int>(c + 2));
	vector<vector<bool>> st(r + 2, vector<bool>(c + 2));
	unordered_map<int, vector<pair<int, int>>> factor;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			factor[i * j].push_back({ i, j });
			cin >> g[i][j];
		}
	}

	q.push(g[1][1]);
	st[1][1] = true;

	while (q.size())
	{
		int num = q.front();
		q.pop();
		for (int i = 0; i < factor[num].size(); i++)
		{
			int a = factor[num][i].first, b = factor[num][i].second;
			if (st[a][b]) continue;
			if (a == r && b == c)
			{
				cout << "yes";
				return 0;
			}
			q.push(g[a][b]);
			st[a][b] = true;
		}
	}
	cout << "no";
	return 0;
}