#include <bits/stdc++.h>
using namespace std;

int rd()
{
	int x = 0; char c = getchar();
	while (!isalnum(c)) c = getchar();
	while (isalnum(c)) x = x * 10 + c - '0', c = getchar();
	return x;
}

const int INF = 0x3f3f3f3f;
const int N = 200010;
int n, w, d;
vector<vector<int>> road(N);
int subway[N], dis[N];

void bfs()
{
	fill(dis, dis + N, INF);
	queue<int> q;
	q.push(n);
	dis[n] = 0;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto v : road[u])
		{
			if (dis[v] != INF) continue;
			dis[v] = dis[u] + 1;
			q.push(v);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd(), w = rd(), d = rd();
	while (w--)
	{
		int u = rd(), v = rd();
		road[v].push_back(u);
	}
	bfs();
	multiset<int> s;
	for (int i = 1; i <= n; i++)
	{
		subway[i] = rd();
		s.insert(i - 1 + dis[subway[i]]);
	}
	while (d--)
	{
		int x = rd(), y = rd();
		s.erase(s.find(x - 1 + dis[subway[x]]));
		s.erase(s.find(y - 1 + dis[subway[y]]));
		swap(subway[x], subway[y]);
		s.insert(x - 1 + dis[subway[x]]);
		s.insert(y - 1 + dis[subway[y]]);
		cout << *s.begin() << '\n';
	}

	return 0;
}