#include <bits/stdc++.h>
using namespace std;

struct node { int x, y; };
const int N = 100;
int indegree[N][N], res[N][N];
string g[N][N];
stack<node> s;
vector<node> e[N][N];

void to2d(int x, int y, string s)
{
	s += '+';
	string t;
	for (auto& c : s)
	{
		if (c != '+') t += c;
		else
		{
			int xx = t[0] - 'A' + 1, yy = t[1] - '0';
			e[xx][yy].push_back({ x,y });
			indegree[x][y]++;
			t.clear();
		}
	}
}

void topo()
{
	while (s.size())
	{
		auto t = s.top(); s.pop();
		for (auto& c : e[t.x][t.y])
		{
			if (isdigit(g[t.x][t.y][0])) 
				res[c.x][c.y] += res[t.x][t.y];
			if (!--indegree[c.x][c.y])
			{
				s.push({ c.x, c.y });
				g[c.x][c.y] = '0';
			}
		}
	}
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (!isdigit(g[i][j].front())) cout << "* ";
			else cout << res[i][j] << " ";
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> g[i][j];
			if (isdigit(g[i][j][0]))
			{
				res[i][j] = stoi(g[i][j]);
				s.push({ i,j });
			}
		}
	}
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (!isdigit(g[i][j][0]))
			{
				to2d(i, j, g[i][j]);
			}
		}
	}

	topo();

	return 0;
}