#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	
	string words[6] =
	{
		"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY"
	};

	double w;
	cin >> w;

	vector<string> wall(ceil(30 / w), "");
	int index = 0;
	int test = ceil(30 / w);
	for (int i = 0; i < ceil(30 / w); i++)
	{
		wall[i] += words[index++];
		while (wall[i].size() + words[index].size() + 1 <= w)
		{
			wall[i] += "." + words[index++];
		}

		int gap = 1;
		while (wall[i].size() < w && count(wall[i].begin(), wall[i].end(), '.') != 0)
		{
			int j = 0;
			while (wall[i].size() < w && j < wall[i].size())
			{
				if (wall[i][j] == '.')
				{
					wall[i].insert(wall[i].begin() + j, '.');
					j += gap;
				}
				j += gap;
			}
			gap++;
		}
	}

	for (auto val : wall)
	{
		if (count(val.begin(), val.end(), '.') == 0)
		{
			cout << setfill('.') << setw(w) << left << val;
		}
		else
		{
			cout << val;
		}
		cout << endl;
	}

	return 0;
}