#include <bits/stdc++.h>
using namespace std;

struct node { int x, y; };
const int N = 110;
node tree[N];
int n, m, res;

bool cmp1(node & n1, node &n2) { return n1.x < n2.x; }
bool cmp2(node & n1, node &n2) { return n1.y < n2.y; }

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> m >> n;
	for (int i = 1; i <= n; i++) cin >> tree[i].x >> tree[i].y;

	m++;
	tree[n + 1] = { 0,0 };
	tree[n + 2] = { m,m };
	tree[n + 3] = { 0,m };
	tree[n + 4] = { m,0 };
	n += 4;

	sort(tree + 1, tree + 1 + n, cmp2);
	for (int i = 1; i <= n; i++)
	{
		int maxn = m, minn = 1;
		for (int j = i + 1; j <= n; j++)
		{
			if (maxn - minn - 1 < tree[j].y - tree[i].y - 1) break;
			res = max(res, tree[j].y - tree[i].y - 1);
			if (tree[j].x <= tree[i].x) minn = max(minn, tree[j].x);
			if (tree[j].x >= tree[i].x) maxn = min(maxn, tree[j].x);
		}
	}
	
	sort(tree + 1, tree + 1 + n, cmp1);
	for (int i = 1; i <= n; i++)
	{
		int maxn = m, minn = 1;
		for (int j = i + 1; j <= n; j++)
		{
			if (maxn - minn - 1 < tree[j].x - tree[i].x - 1) break;
			res = max(res, tree[j].x - tree[i].x - 1);
			if (tree[j].y <= tree[i].y) minn = max(minn, tree[j].y);
			if (tree[j].y >= tree[i].y) maxn = min(maxn, tree[j].y);
		}
	}

	cout << res;
	return 0;
}