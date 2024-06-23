#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
inline int rd()
{
	int x = 0; char ch = getchar();
	while (ch<'0' || ch>'9') ch = getchar();
	while (ch >= '0' && ch <= '9')
		x = x * 10 + ch - '0', ch = getchar();
	return x;
}

const int N = 1e5 + 10;
int n;
double res;
tree<int, null_type, greater_equal<int>,
	rb_tree_tag,
	tree_order_statistics_node_update>
	t;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd();
	for (int i = 1; i <= n; i++)
	{
		int x = rd();
		t.insert(x);
		res += t.order_of_key(x) + 1;
	}
	cout << fixed << setprecision(2) << res / n;

	return 0;
}