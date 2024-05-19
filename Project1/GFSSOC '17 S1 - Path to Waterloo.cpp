#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int n, t;
unordered_map<string, int> dis;
unordered_map<string, vector<string>> m;

void bfs()
{
	queue<string> q;
	q.push("home");
	dis["home"] = 0;
	dis["Waterloo GO"] = -1;

	while (q.size())
	{
		auto t = q.front(); q.pop();
		for (int i = 0; i < m[t].size(); i++)
		{
			string v = m[t][i];
			if (dis[v] >= 0) continue;
			dis[v] = dis[t] + 1;
			q.push(v);
			if (v == "Waterloo GO")
			{
				cout << dis[v];
				return;
			}
		}
	}
	cout << "RIP ACE";
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	string _;
	cin >> n >> t; cin.get();
	while (n--)
	{
		getline(cin, _);
		dis[_] = -1;
	}

	while (t--)
	{
		string u, v;
		getline(cin, _);
		for (int i = 0; i < _.size(); i++)
		{
			if (_[i] == '-')
			{
				for (int j = i + 1; j < _.size(); j++) v += _[j];
				break;
			}
			u += _[i];
		}
		m[u].push_back(v);
		m[v].push_back(u);
	}
	bfs();

	return 0;
}