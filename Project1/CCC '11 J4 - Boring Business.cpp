#include <bits/stdc++.h>
using namespace std;

bool table[205][500];
int x = 0, y = 250;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	for (int i = 0; i < 3; i++)
		table[++x][y] = 1;
	for (int i = 0; i < 3; i++)
		table[x][++y] = 1;
	for (int i = 0; i < 2; i++)
		table[++x][y] = 1;
	for (int i = 0; i < 2; i++)
		table[x][++y] = 1;
	for (int i = 0; i < 2; i++)
		table[--x][y] = 1;
	for (int i = 0; i < 2; i++)
		table[x][++y] = 1;
	for (int i = 0; i < 4; i++)
		table[++x][y] = 1;
	for (int i = 0; i < 8; i++)
		table[x][--y] = 1;
	for (int i = 0; i < 2; i++)
		table[--x][y] = 1;

	int v;
	char d;
	int px = -1, py = -5;
	while (cin >> d >> v)
	{
		if (d == 'q')
			break;

		if (d == 'l')
		{
			for (int i = 1; i <= v; i++)
			{
				if (table[x][y - 1] != 1)
				{
					table[x][y -= 1] = 1;
				}
				else if (table[x][y - 1] == 1)
				{
					cout << px - v << " " << py << " DANGER" << endl;
					exit(0);
				}
			}
			cout << (px -= v) << " " << py << " safe" << endl;
		}
		else if (d == 'd')
		{
			for (int i = 1; i <= v; i++)
			{
				if (table[x + 1][y] != 1)
				{
					table[x += 1][y] = 1;
				}
				else if (table[x + 1][y] == 1)
				{
					cout << px << " " << py - v << " DANGER" << endl;
					exit(0);
				}
			}
			cout << px << " " << (py -= v) << " safe" << endl;
		}
		else if (d == 'r')
		{
			for (int i = 1; i <= v; i++)
			{
				if (table[x][y + 1] != 1)
				{
					table[x][y += 1] = 1;
				}
				else if (table[x][y + 1] == 1)
				{
					cout << px + v << " " << py << " DANGER" << endl;
					exit(0);
				}
			}
			cout << (px += v) << " " << py << " safe" << endl;
		}
		else if (d == 'u')
		{
			for (int i = 1; i <= v; i++)
			{
				if (table[x - 1][y] != 1)
				{
					table[x -= 1][y] = 1;
				}
				else if (table[x - 1][y] == 1)
				{
					cout << px << " " << py + v << " DANGER" << endl;
					exit(0);
				}
			}
			cout << px << " " << (py += v) << " safe" << endl;
		}
	}

	return 0;
}