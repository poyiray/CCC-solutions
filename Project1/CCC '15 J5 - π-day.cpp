#include <bits/stdc++.h>
using namespace std;

const int N = 260;
int mem[N][N][N];

int dfs(int n, int k, int s)
{
	if (mem[n][k][s]) return mem[n][k][s];
	if (k == 1) return 1;
	for (int i = s; i <= n / k; i++)
		mem[n][k][s] += dfs(n - i, k - 1, i);
	return mem[n][k][s];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	cout << dfs(n, k, 1);
	return 0;
}