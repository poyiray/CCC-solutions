#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int x, y, g, sum = 0;
	string input;
	
	cin >> x;
	vector<vector<string>> must(x);
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> input;
			must[i].push_back(input);
		}
	}
	cin >> y;
	vector<vector<string>> must_not(y);

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> input;
			must_not[i].push_back(input);
		}
	}
	cin >> g;
	vector<vector<string>> group(g);
	
	int idx1 = 0;
	int idx2 = 0;
	int in_pair = 0;
	for (int i = 0; i < g; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> input;
			group[i].push_back(input);
		}
		sum = count(group[i].begin(), group[i].end(), must[idx1][0]) + count(group[i].begin(), group[i].end(), must[idx1][1]);
		if (sum == 2)
		{
			in_pair++;
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < g; j++)
		{
			int temp = count(group[j].begin(), group[j].end(), must[i][0]) + count(group[j].begin(), group[j].end(), must[i][1]);
			
			if (temp == 1)
			{
				sum++;
				break;
			}
			else if (temp == 2)
			{
				break;
			}
			else
			{
				if (j == g - 1)
				{
					sum++;
				}
			}
		}
	}

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < g; j++)
		{
			int temp = count(group[j].begin(), group[j].end(), must_not[i][0]) + count(group[j].begin(), group[j].end(), must_not[i][1]);

			if (temp == 2)
			{
				sum++;
				break;
			}
		}
	}

	cout << sum;
	return 0;
}