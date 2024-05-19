//unsolved
#include <iostream>
#include <deque>
#include <string>
#include <queue>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		deque<int> n;
		priority_queue<int, vector<int>, greater<int>> q;
		for (auto val : s) n.push_back(val - '0');
		int k; cin >> k;
		for (int i = 0; i < n.size(); i++)
		{
			if (!k) break;
			while (i < n.size() - 1 && k && n[i + 1] < n[i])
			{
				q.push(n[i]);
				n.erase(n.begin() + i);
				k--;
			}
		}

		if (k > 0)
		{
			q.push(n.back()); n.erase(n.end() - 1);
		}
		while (!q.empty())
		{
			n.push_back(q.top()); q.pop();
		}

		for (auto val : n) cout << val;
		cout << endl;
	}

	return 0;
}