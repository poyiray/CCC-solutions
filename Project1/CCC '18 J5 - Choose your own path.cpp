#include <queue>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int N = 10010;
int dist[N];
vector<int> jump[N];
vector<int> res;
int n;


void bfs()
{
	queue<int> q;
	q.push(1);
	dist[1] = 1;

	while (q.size())
	{
		int num = q.front(); q.pop();
		for (int i = 0; i < jump[num].size(); i++)
		{
			int a = jump[num][i];
			if (dist[a] >= 1) continue;
			dist[a] = dist[num] + 1;
			if (a == 0 || jump[a][0] == 0) continue;
			q.push(a);
		}
	}
}

int main()
{
	//freopen("input.txt", "r", stdin);
	int input;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		if (input == 0)
		{
			jump[i].push_back(0);
			res.push_back(i);
		}
		for (int j = 0; j < input; j++)
		{
			int temp; cin >> temp;
			jump[i].push_back(temp);
		}
	}

	bfs();
	
	int cnt = 1e9; bool flag = true;
	for (auto val : res)
	{
		if (cnt > dist[val] && dist[val] != 0) cnt = dist[val];
	}
	
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == 0)
		{
			flag = false;
		}
	}

	if (flag) cout << "Y" << endl;
	else cout << "N" << endl;
	cout << cnt << endl;

	return 0;
}