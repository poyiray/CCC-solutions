#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e3;
struct Line
{
	int x1, x2, t, id;
};
struct Point
{
	int x, t, id;
	bool operator<(const Point &p) const
	{
		return x < p.x;
	}
	bool operator==(const Point &p) const
	{
		return id == p.id;
	}
};
int n, k, Y[N], ly, idx;
ll res;
vector<Point> X;
map<int, vector<Line>> line;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		int x1, y1, x2, y2, t; cin >> x1 >> y1 >> x2 >> y2 >> t;
		Y[++ly] = y1;
		Y[++ly] = y2;
		line[y1].push_back({ x1, x2, t, ++idx });
		line[y2].push_back({ x1,x2,-t, idx });
	}
	sort(Y + 1, Y + ly + 1);
	int s = unique(Y + 1, Y + ly + 1) - Y - 1;
	for (int i = 1; i < s; i++)
	{
		int cnt = 0, high = Y[i + 1] - Y[i];
		for (auto &[x1, x2, t, id] : line[Y[i]])
		{
			if (t < 0)
			{
				X.erase(find(X.begin(), X.end(), Point{ 0, 0, id }));
				X.erase(find(X.begin(), X.end(), Point{ 0, 0, id }));
			}
			else
			{
				X.push_back({ x1, t, id });
				X.push_back({ x2, -t, id });
			}
		}
		sort(X.begin(), X.end());
		for (int j = 0; j < X.size() - 1; j++)
		{
			cnt += X[j].t;
			if (cnt >= k) res += (ll)high * (X[j + 1].x - X[j].x);
		}
	}
	cout << res;

	return 0;
}