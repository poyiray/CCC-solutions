#include <bits/stdc++.h>
using namespace std;
int r, c, n;
//#pragma GCC optimize("Ofast")
void moving(int x, int y, vector<char> move, vector<vector<char>>& map, vector<vector<vector<int>>>& loc)
{
	int d[4][2] =
	{
		{0, 1},
		{1, 0},
		{0, -1},
		{-1, 0}
	};
	int temp_x = x, temp_y = y;
	int size = move.size();
	for (int i = 0; i < 4; i++)
	{
		int index = 1;
		int facing = i;
		x = temp_x; y = temp_y;
		loc[i][0][0] = x;
		loc[i][0][1] = y;
		for (int j = 0; j < size; j++)
		{
			if (move[j] == 'R')
			{
				facing = (facing + 1) % 4;
			}
			else if (move[j] == 'L')
			{
				facing = facing - 1;
				if (facing == -1)
				{
					facing = 3;
				}
			}
			else if (move[j] == 'F')
			{
				loc[i][index][0] = x += d[facing][0];
				loc[i][index][1] = y += d[facing][1];
				index++;
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	clock_t startTime = clock();
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	
	cin >> r >> c;
	vector<vector<char>> map(r + 2, vector<char>(c + 2));
	char input;
	int num_f = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> input;
			map[i][j] = input;
		}
	}

	cin >> n;
	vector<char> move;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input == 'F')
		{
			num_f++;
		}
		move.push_back(input);
	}
	vector<vector<vector<int>>> loc(4, vector<vector<int>>(num_f + 1, vector<int>(2)));

	moving(1, 1, move, map, loc);

	bool flag = false;
	for (int i = 0; i <= r; i++)
	{
		for (int j = 0; j <= c; j++)
		{
			for (auto arr2 : loc)
			{
				if (arr2[num_f][0] + i > r || arr2[num_f][0] + i < 1)
					continue;
				if (arr2[num_f][1] + j > c || arr2[num_f][1] + j < 1)
					continue;
				if (map[arr2[num_f][0] + i][arr2[num_f][1] + j] == 'X' || map[arr2[0][0] + i][arr2[0][1] + j] == 'X')
					continue;

				flag = false;
				for (auto arr : arr2)
				{
					if (arr[0] + i > r || arr[0] + i < 1 || arr[1] + j > c || arr[1] + j < 1)
					{
						flag = true;
						break;
					}
					if (map[arr[0] + i][arr[1] + j] == 'X')
					{
						flag = true;
						break;
					}
						
				}
				if (!flag)
				{
					map[arr2[num_f][0] + i][arr2[num_f][1] + j] = '*';
				}
			}
		}
	}

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}

	clock_t endTime = clock();
	cout << "整个程序用时：" << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	return 0;
}