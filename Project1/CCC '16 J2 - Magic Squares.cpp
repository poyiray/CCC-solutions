#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<vector<int>> m(4, vector<int>(4));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			cin >> m[i][j];

	vector<int> num1(4, 0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			num1[i] += m[i][j];
		}
	}

	vector<int> num2(4, 0);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			num2[i] += m[j][i];
		}
	}

	if (count(num1.begin(), num1.end(), num1[0]) == 4 && count(num2.begin(), num2.end(), num2[0]) == 4
		&& num1[0] == num2[0])
	{
		cout << "magic";
	}
	else
	{
		cout << "not magic";
	}

	cout << endl;
	return 0;
}