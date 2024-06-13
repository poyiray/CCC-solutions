#include <bits/stdc++.h>
using namespace std;

const int N = 3010;
char s1[N], s2[N];
int a, b, f[N][N]; 

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> s1 + 1 >> s2 + 1;
	a = strlen(s1 + 1), b = strlen(s2 + 1);
	
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			if (s1[i] == s2[j]) f[i][j] = f[i - 1][j - 1] + 1;
			else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
		}
	}

	int i = a, j = b;
	string res;
	while (i && j)
	{
		if (s1[i] == s2[j])
		{
			res += s1[i];
			i--, j--;	
		}
		else
		{
			if (f[i][j - 1] > f[i - 1][j]) j--;
			else i--;
		}
	}
	reverse(res.begin(), res.end());
	cout << res;
	return 0;
}