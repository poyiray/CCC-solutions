#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);

	int h, n = 3;
	vector<vector<char>> c;
	cin >> h;
	c.resize(h);

	c[0].push_back('*');
	for (int i = 0; i < h - 1; i++)
	{
		c[0].push_back(' ');
	}

	for (int i = 1; i < h / 2; i++)
	{
		for (int j = 0; j < h; j++)
		{
			if (j < n)
			{
				c[i].push_back('*');
			}
			else
			{
				c[i].push_back(' ');
			}
		}
		n += 2;
	}

	for (int i = 0; i < h; i++)
	{
		c[h / 2].push_back('*');
	}


	for (int i = 0; i < h / 2; i++)
	{
		for (int j = 0; j < h; j++)
		{
			cout << c[i][j];
		}
		for (int j = h - 1; j >= 0; j--)
		{
			cout << c[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < h; i++)
	{
		cout << c[h / 2][i] << c[h / 2][i];
	}
	cout << endl;

	for (int i = h / 2 - 1; i >= 0; i--)
	{
		for (int j = 0; j < h; j++)
		{
			cout << c[i][j];
		}
		for (int j = h - 1; j >= 0; j--)
		{
			cout << c[i][j];
		}
		cout << endl;
	}

	return 0;
}