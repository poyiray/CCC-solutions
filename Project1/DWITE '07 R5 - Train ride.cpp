#include <bits/stdc++.h>
using namespace std;

vector<string> g;

int dis[10][20];
int dx[] = { -1,-1,-1,0, 0,1,1, 1 };
int dy[] = {  1, 0,-1,1,-1,1,0,-1 };

int x, y;

void bfs()
{
	memset(dis, -1, sizeof dis);
	queue<pair<int, int>> q;
	q.push({ x,y });
	dis[x][y] = 0;
	
	while (q.size())
	{
		auto t = q.front(); q.pop();
		for (int i = 0; i < 8; i++)
		{
			int a = t.first + dx[i], b = t.second + dy[i];
			if (a < 0 || a >= g.size() || b < 0 || b >= 10) continue;
			if (dis[a][b] >= 0) continue;
			if (g[a][b] == ' ') continue;
			dis[a][b] = dis[t.first][t.second] + 1;
			q.push({ a,b });
			if (g[a][b] == 'E')
			{
				cout << dis[a][b] << endl;
				return;
			}
		}
	}
}

int main()
{
	int n = 5;
	while (n--)
	{
		for (int i = 0; i < 11; i++)
		{
			string input; getline(cin, input);
			if (input[0] == 'x') break;
			for (int j = 0; j < 10; j++)
			{
				if (input[j] == 'S') x = i, y = j;
			}
			g.push_back(input);
		}
		bfs();
		g.clear();
	}

	return 0;
}