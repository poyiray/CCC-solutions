#include <bits/stdc++.h>
using namespace std;

const int N = 5, M = 100;
int a[N][N];
vector<int> num[N][N];
char b[N][N];
bool vis[N][N];


int main()
{
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			char c; cin >> c;
			if (c == 'X') b[i][j] = 'X';
			else a[i][j] = c - '0';
		}
	}



	return 0;
}