#include <bits/stdc++.h>
using namespace std;
int table[10][10];
int x[8] = { 0, 1, 1, 1, 0,-1,-1,-1 };
int y[8] = { 1, 1, 0,-1,-1,-1, 0, 1 };
int r, c;
char config;

void moving(int r, int c, bool& flag, int d, bool color)
{
	if (r + x[d] > 8 || r + x[d] < 1)
		return;
	if (c + y[d] > 8 || c + y[d] < 1)
		return;
	if (table[r + x[d]][c + y[d]] == 0)
		return;

	c += y[d];
	r += x[d];
	moving(r, c, flag, d, color);
	if (color == 0)
	{
		if (flag)
		{
			table[r][c] = 2;
			return;
		}
		if (table[r][c] == 2)
		{
			flag = true;
		}
	}
	else
	{
		if (flag)
		{
			table[r][c] = 1;
			return;
		}
		if (table[r][c] == 1)
		{
			flag = true;
		}
	}
}


int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	
	cin >> config;

	switch (config)
	{
	case 'a':
		table[4][4] = 2;
		table[4][5] = 1;
		table[5][4] = 1;
		table[5][5] = 2;
		break;
	case 'b':
		for (int i = 1, j = 1; i <= 8; i++, j++)
			table[i][j] = 1;
		for (int i = 1, j = 8; i <= 8; i++, j--)
			table[i][j] = 2;
		break;
	case 'c':
		for (int i = 1; i <= 8; i++)
			for (int j = 3; j <= 4; j++)
				table[i][j] = 1;

		for (int i = 1; i <= 8; i++)
			for (int j = 5; j <= 6; j++)
				table[i][j] = 2;
		break;
	}

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> r >> c;
		int color = i % 2;
		if (!color)
			table[r][c] = 2;
		else
			table[r][c] = 1;

		for (int j = 0; j < 8; j++)
		{
			bool flag = false;
			moving(r, c, flag, j, color);
		}
	}

	int num1 = 0, num2 = 0;

	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			if (table[i][j] == 1)
			{
				num1++;
			}
			else if (table[i][j] == 2)
			{
				num2++;
			}
		}
	}

	cout << num1 << " " << num2;

	return 0;
}