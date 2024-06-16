#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
	return x;
}
struct query
{
	char opt; int n, r;
};
struct node
{
	int n, r;
	bool operator>(const node &nd) const
	{
		return r > nd.r;
	}
};
const int N = 1e6 + 10;
int num[N];
query a[N];
tree<node, null_type, greater<node>,
	rb_tree_tag,
	tree_order_statistics_node_update> s;

void solve()
{
	char opt = getchar();
	if (opt == 'N')
	{
		int n = rd(), r = rd();
		num[n] = r;
		s.insert({ n,r });
	}
	else if (opt == 'M')
	{
		int n = rd(), r = rd();
		int pr = num[n];
		s.erase(s.lower_bound({ n, pr }));
		s.insert({ n,r });
		num[n] = r;
	}
	else
	{
		int n = rd();
		cout << s.find_by_order(n - 1)->n << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int _ = rd();
	while (_--) solve();

	return 0;
}
