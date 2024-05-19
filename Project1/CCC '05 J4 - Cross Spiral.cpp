#include <bits/stdc++.h>
using namespace std;

int table[20 + 5][20 + 5];
int vx[12] = { 0, 1, 0, 1, 0, 1, 0,-1, 0,-1, 0,-1 };
int vy[12] = { 1, 0, 1, 0,-1, 0,-1, 0,-1, 0, 1, 0 };
int w, h, cw, ch, steps;
int a, b, x, y, counter = 0, step_counter = 0;
bool flag = false;

void move(int a, int j)
{
	while (counter != a)
	{
		if (table[x + vx[j]][y + vy[j]] == 1)
			break;
		table[x += vx[j]][y += vy[j]] = 1;
		flag = true;
		counter++;
		step_counter++;
		if (step_counter == steps)
		{
			cout << y << endl << x;
			exit(0);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	cin >> w >> h >> cw >> ch >> steps;
	a = w - 2 * cw - 1, b = h - 2 * ch - 1;
	y = cw + 1; x = 1; table[x][y] = 1;
	while (true)
	{
		for (int j = 0; j < 12; j++)
		{
			if (j + 1 == 1 || j + 1 == 7) move(a, j);
			else if (j + 1 == 4 || j + 1 == 10) move(b, j);
			else if (j + 1 == 2 || j + 1 == 6 || j + 1 == 8 || j + 1 == 12) move(ch, j);
			else move(cw, j);
			counter = 0;
		}
		if (!flag)
		{
			cout << y << endl << x;
			return 0;
		}
		flag = false;
	}
}