#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
using namespace std;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void move(int arr[][13], int d, int& x, int& y, int& start, int& end, int r)
{
	for (int i = 0; i < r && start < end; i++)
	{
		arr[x += dx[d]][y += dy[d]] = ++start;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int start, end, x = 5, y = 5, arr[13][13], r = 1;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			arr[i][j] = 0;
		}
	}
	cin >> start >> end;
	arr[5][5] = start;

	while (start < end)
	{
		for (int i = 1; i <= 4; i++)
		{
			move(arr, i - 1, x, y, start, end, r);
			if (i % 2 == 0)
			{
				r++;
			}
			if (i == 1)
			{
				while (arr[x + 1][y + 1] && arr[x + 1][y] == 0)
				{
					arr[++x][y] = -1;
				}
			}
			else if (i == 2)
			{
				while (arr[x - 1][y + 1] && arr[x][y + 1] == 0)
				{
					arr[x][++y] = -1;
				}
			}
			else if (i == 3)
			{
				while (arr[x - 1][y - 1] && arr[x - 1][y] == 0)
				{
					arr[--x][y] = -1;
				}
			}
			else
			{
				while (arr[x + 1][y - 1] && arr[x][y - 1] == 0)
				{
					arr[x][--y] = -1;
				}
			}
		}
	}

	int num[13], sum = 0, index = 0;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (arr[i][j] != 0)
			{
				sum++;
			}
		}
		num[i] = sum;
		sum = 0;
	}

	sort(num, num + 13);

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (arr[i][j] == -1)
			{
				cout << "   ";
				index++;
			}
			else if (arr[i][j] != 0)
			{
				cout << setw(2) << arr[i][j] << " ";
				index++;
			}
			if (index == num[12])
			{
				index = 0;
				cout << endl;
			}
		}
	}
	return 0;
}