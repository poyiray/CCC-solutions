#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int c = 0;
	cin >> c;
	int input;
	vector<vector<int>> arr;
	arr.resize(2);

	int length = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> input;
			if (input == 1)
			{
				length += 3;
			}
			arr[i].push_back(input);
		}
	}

	for (int i = 0; i < c; i++)
	{
		if (arr[0][i] == 1)
		{
			if (i < c - 1)
			{
				if (arr[0][i + 1] == 1)
				{
					length -= 2;
				}

			}


			if ((i + 1) % 2 != 0)
			{
				if (arr[1][i] == 1)
				{
					length -= 2;
				}
			}
		}
	}

	for (int i = 0; i < c - 1; i++)
	{
		if (arr[1][i] == 1)
		{
			if (arr[1][i + 1] == 1)
			{
				length -= 2;
			}
		}
	}

	cout << length << endl;

	return 0;
}