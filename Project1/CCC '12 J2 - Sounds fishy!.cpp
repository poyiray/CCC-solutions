#include <bits/stdc++.h>
using namespace std;

int fish[4];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	for (int i = 0; i < 4; i++) cin >> fish[i];
	int a = fish[0] - fish[1];
	for (int i = 0; i < 3; i++)
	{
		int b = fish[i] - fish[i + 1];
		if ((a > 0 && (b < 0 || b == 0)) || (a < 0 && (b > 0 || b == 0)) || (a == 0 && (b > 0 || b < 0)))
		{
			cout << "No Fish";
			return 0;
		}
	}
	if (a > 0) cout << "Fish Diving";
	else if (a < 0) cout << "Fish Rising";
	else cout << "Fish At Constant Depth";
	return 0;
}