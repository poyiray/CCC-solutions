#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1000;
ll motel[N] = { 0,0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000 };
ll a, b, n = 15, m, res[N], mem[N], f[N];

//¼Ó¼ÇÒä»¯ËÑË÷
ll dfs(int x)
{
	if (mem[x]) return mem[x];
	if (motel[x] == 7000) return 1;
	for (int i = x + 1; i < n; i++)
	{
		if (motel[i] - motel[x] < a || motel[i] - motel[x] > b) continue;
		mem[x] += dfs(i);
	}
	return mem[x];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> a >> b >> m;
	while (m--)
	{
		int u; cin >> u;
		motel[n++] = u;
	}
	sort(motel + 1, motel + n);
	f[1] = 1;
	for(int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			int dif = motel[j] - motel[i];
			if (dif < a) continue;
			else if (dif > b) break;
			f[j] += f[i];
		}
	}
	cout << f[n - 1] << '\n';
	//cout << dfs(1) << '\n';

	return 0;
}