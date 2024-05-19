#include<iostream>
using namespace std;

int main()
{
	int output[5][5], distance[6], left = 0, right = 0;
	for (int i = 1; i <= 4; i++)
	{
		cin >> distance[i];
	}

	distance[0] = 0;
	distance[5] = 0;

	output[0][0] = 0;
	output[1][1] = 0;
	output[2][2] = 0;
	output[3][3] = 0;
	output[4][4] = 0;

	int j, z;
	for (int i = 0; i < 5; i++)
	{
		j = i - 1;
		z = i + 1;
		while (z <= 4)
		{
			right += distance[z];
			output[i][z] = right;
			z++;
		}

		while (j >= 0)
		{
			left += distance[j + 1];
			output[i][j] = left;
			j--;
		}
		left = right = 0;
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << output[i][j];
			if (!(i == 4 && j == 4))
			{
				cout << " ";
			}
		}
		if (i == 4) break;
		cout << endl;
	}

	return 0;
}