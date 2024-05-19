#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int a[N], m, res[N], in[N];

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> m;
	bool f = false;
	while (m--)
	{
		char c; int n; cin >> c >> n;
		if (c == 'R')
		{
			if (!f)
			{
				for (int i = 0; i < N; i++)
				{
					if (in[i]) a[i]++;
				}
			}
			f = false;
			in[n] = 1;
		}
		else if (c == 'S')
		{
			if (!f)
			{
				for (int i = 0; i < N; i++)
				{
					if (in[i]) a[i]++;
				}
			}
			f = false;
			res[n] += a[n];
			a[n] = 0;
			in[n] = 0;
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				if (in[i]) a[i] += n;
			}
			f = true;
		}
	}
	for (int i = 0; i < N; i++)
	{
		if (in[i]) cout << i << " " << -1 << '\n';
		else if (res[i])
		{
			cout << i << " " << res[i] << '\n';
		}
	}

	return 0;
}