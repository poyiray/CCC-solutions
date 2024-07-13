#include <bits/stdc++.h> //±©Á¦³öÆæ¼£
using namespace std;

const int N = 110, M = 5e6 + 1e3;
vector<int> f1, f2, ans;
bool vis[M];
int n, sum, k[N], c[N], res = INT_MAX;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> k[i] >> c[i];
		sum += k[i] * c[i];
	}

	for (int i = 1; i <= k[1] / 2 + 1; i++)
	{
		int u = i * c[1];
		f1.push_back(u);
		f2.push_back(u);
		ans.push_back(u);
		vis[u] = 1;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= k[i] / 2 + 1; j++)
		{
			int u = j * c[i];
			if(!vis[u]) f1.push_back(u), ans.push_back(u), vis[u] = 1;
			for (auto &x : f2)
			{
				if (vis[u + x]) continue;
				vis[u + x] = 1;
				f1.push_back(u + x);
				ans.push_back(u + x);
			}
		}
		f2.swap(f1);
	}

	for(auto &i : ans)
	{
		res = min(res, abs(sum - i - i));
	}
	cout << res;

	return 0;
}