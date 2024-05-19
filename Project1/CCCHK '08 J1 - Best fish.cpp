#include <bits/stdc++.h>
using namespace std;

int n;
set<int, greater<int>> res[2];

int main()
{
	for (int i = 0; i < 2; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int w, l; cin >> w >> l;
			res[i].insert(w * l);
		}
	}
	if (*res[0].begin() > *res[1].begin()) cout << "Casper";
	else if (*res[0].begin() < *res[1].begin()) cout << "Natalie";
	else cout << "Tie";

	return 0;
}