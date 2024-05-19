#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	vector<vector<int>> data(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> data[i][j];
	
	if (data[n - 1][0] < data[n - 2][0])
	{
		if (data[n - 1][0] < data[n - 1][n - 1])
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = n - 1; j >= 0; j--)
				{
					cout << data[j][i] << " ";
				}
				cout << endl;
			}
		}
		else
		{
			for (int i = n - 1; i >= 0; i--)
			{
				for (int j = n - 1; j >= 0; j--)
				{
					cout << data[j][i] << " ";
				}
				cout << endl;
			}
		}
	}

	return 0;
}