#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct pos
{
	pos() {};
	pos(int X, int Y) : x(X), y(Y) {};
	int x, y;
}
;
bool isfound(vector<pos>& tree, int val)
{
	for (auto num : tree)
	{
		if (num.x == val)
			return true;
	}
	return false;
}

int main()
{
	int m, n;
	cin >> m >> n;
	vector<int> pool;
	vector<pos> tree(n);

	for (int i = 0; i < n; i++)
		cin >> tree[i].x >> tree[i].y;
	tree.push_back(pos(0, 0)); tree.push_back(pos(m + 1, 0));
	tree.push_back(pos(0, m + 1)); tree.push_back(pos(m + 1, m + 1));
	sort(tree.begin(), tree.end(), [](pos x, pos y) {return x.y < y.y; });
	vector<int> X;
	for (auto val : tree)
		X.push_back(val.x);

	for (int i = 0; i < tree.size(); i++)
	{
		for (int j = i; j < tree.size(); j++)
		{
			int top, down, width = tree[j].y - tree[i].y;
			down = top = round(tree[j].x + tree[j].x) / 2;

			while (top < 0 || down >= m)
			{
				if (!isfound(tree, top) && !isfound(tree, down) || down - top > width)
				{
					if (down - top > width)
						pool.push_back(down - top);
					else
						pool.push_back(width);
				}
				if (!isfound(tree, top) && )
					top--;
				if (!isfound(tree, down))
					down++;
			}
		}
	}

	return 0;
}