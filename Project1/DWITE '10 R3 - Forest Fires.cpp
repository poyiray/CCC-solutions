#include <bits/stdc++.h>
using namespace std;

vector<string> g;
vector<pair<int, int>> fire;
int dis[20][20];
int res;
int nt;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

void bfs()
{
	memset(dis, -1, sizeof dis);
	int t = 0;
	queue<pair<int, int>> q;
	for (auto val : fire)
	{
		dis[val.first][val.second] = 0;
		q.push({ val.first, val.second });
	}

	while (q.size())
	{
		auto t = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int a = t.first + dx[i], b = t.second + dy[i];
			if (a < 0 || a >= 10 || b < 0 || b >= 10) continue;
			if (dis[a][b] >= 0) continue;
			if (g[a][b] != 'T') continue;
			dis[a][b] = res = dis[t.first][t.second] + 1;
			g[a][b] = 'F';
			nt--;
			q.push({ a,b });
		}
	}
}

int main()
{
	string input;
	int _ = 5;
	while (_--)
	{
		g.clear();
		fire.clear();
		res = 0;
		nt = 0;
		for (int i = 0; i < 10; i++)
		{
			cin >> input;
			for (int j = 0; j < 10; j++)
			{
				if (input[j] == 'F') fire.push_back({ i,j });
				else if (input[j] == 'T') nt++;
			}
			g.push_back(input);
		}
		string s; cin >> s;
		bfs();
		if (nt != 0) cout << -1 << endl;
		else cout << res << endl;
	}

	return 0;
}