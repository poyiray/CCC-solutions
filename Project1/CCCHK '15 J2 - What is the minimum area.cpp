#include <bits/stdc++.h>
using namespace std;

const int N = 120;
pair<int, int> cor[N];
int res = INT_MAX;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, y; cin >> x >> y;
		cor[i].first = x, cor[i].second = y;
	}
	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int l = abs(cor[i].first - cor[j].first),
				w = abs(cor[i].second - cor[j].second);
			res = min(res, (int)pow(max(l, w), 2));
		}
	}
	cout << res;

	return 0;
}