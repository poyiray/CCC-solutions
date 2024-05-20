#include <bits/stdc++.h>
using namespace std;

int m, n;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	//freopen("out.txt", "w", stdout);
	cin >> m;
	while (m--)
	{
		int ud, ol = 0, el = 0, cnt = 0;
		cin >> ud;
		while (ud != 0 || ol != 1)
		{
			cout << "Round " << cnt++ << ": " << ud << " undefeated, " << ol << " one-loss, " << el << " eliminated" << endl;
			if (ud == 1 && ol == 1)
			{
				ud = 0;
				ol = 2;
			}
			else
			{
				el += ol / 2;
				ol = ol - ol / 2 + ud / 2;
				ud -= ud / 2;
			}
		}
		cout << "Round " << cnt++ << ": " << ud << " undefeated, " << ol << " one-loss, " << el << " eliminated" << endl;
		cout << "There are " << cnt - 1 << " rounds." << endl;
		if (m) cout << endl;
	}

	return 0;
}