#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}

int main()
{
	priority_queue<pair<long, int>> q;
	unordered_map<int, long> m;
	int n; cin >> n;
	while (n--) m[read()]++;
	for (auto val : m) q.push({val.second, val.first});

	int higest = -1, lowest = 0x3f3f3f3f;
	int higest2 = -1, lowest2 = 0x3f3f3f3f;
	int idx = q.top().first;
	while (q.size())
	{
		int b = q.top().first;
		int a = q.top().second;
		if (b != idx && higest != lowest) break;
		if (b != idx && higest == lowest)
		{
			while (q.size())
			{	
				a = q.top().second; 
				if (q.top().first != b) break;
				q.pop();
				if (a > higest2) higest2 = a;
				if (a < lowest2) lowest2 = a;
			}
			break;
		}
		q.pop();
		if (a > higest) higest = a;
		if (a < lowest) lowest = a;
	}

	if (higest2 != -1 && lowest2 != 0x3f3f3f3f)
	{
		int a = abs(higest2 - higest), b = abs(lowest2 - higest);
		cout << max(a, b);
	}
	else
	{
		cout << abs(higest - lowest);
	}

	return 0;
}