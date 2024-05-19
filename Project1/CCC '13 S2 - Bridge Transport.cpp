#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int w, n, arr[N], res;
bool f;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> w >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n - 3; i++)
	{
		int temp = 0, cnt = 0;
		f = false;
		for (int j = 0; j < 4; j++)
		{
			temp += arr[i + j];
			if (temp > w) { f = true; break; }
			cnt++;
		}
		if (!f) res++;
		else { res += cnt; break; }
	}
	if (arr[n - 2] + arr[n - 1] + arr[n - 3] < w && !f) res += 3;
	cout << res;
	return 0;
}