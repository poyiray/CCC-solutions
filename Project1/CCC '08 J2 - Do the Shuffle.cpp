#include <bits/stdc++.h>
using namespace std;

int main()
{
	deque<char> d = { 'A','B','C','D','E' };
	int b, n;
	while (cin >> b >> n)
	{
		if (b == 4) break;
		for (int i = 0; i < n; i++)
		{
			if (b == 1) d.push_back(d.front()), d.pop_front();
			else if (b == 2) d.insert(d.begin(), d.back()), d.pop_back();
			else swap(d[0], d[1]);
		}
	}
	for (auto v : d) cout << v << " ";
	return 0;
}