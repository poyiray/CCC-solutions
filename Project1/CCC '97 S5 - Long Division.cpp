#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int a[N], b[N], c[N];
char A[N], B[N];

bool cmp(int last)
{
	if (a[last + b[0]]) return 1;
	for (int i = b[0]; i >= 1; i--)
	{
		if (a[last + i - 1] < b[i]) return 0;
		if (a[last + i - 1] > b[i]) return 1;
	}
	return 1;
}

void div()
{
	for (int i = c[0]; i >= 1; i--)
	{
		while (cmp(i))
		{
			for (int j = 1; j <= b[0]; j++)
			{
				a[i + j - 1] -= b[j];
				if (a[i + j - 1] < 0)
				{
					a[i + j] -= 1;
					a[i + j - 1] += 10;
				}
			}
			c[i]++;
		}
	}
	if (c[0] >= 2 && !c[c[0]]) c[0]--;
	while (a[0] >= 2 && !a[a[0]]) a[0]--;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int _; cin >> _;
	while (_--)
	{
		memset(c, 0, sizeof c);
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		cin >> A + 1 >> B + 1;
		a[0] = strlen(A + 1);
		b[0] = strlen(B + 1);
		c[0] = a[0] - b[0] + 1;
		for (int i = a[0]; i >= 1; i--) a[a[0] - i + 1] = A[i] - '0';
		for (int i = b[0]; i >= 1; i--) b[b[0] - i + 1] = B[i] - '0';
		div();
		if (c[0] <= 0) cout << 0;
		else for (int i = c[0]; i >= 1; i--) cout << c[i]; cout << '\n';
		for (int i = a[0]; i >= 1; i--) cout << a[i]; cout << '\n';
		if (_) cout << '\n';
	}

	return 0;
}