#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int r, c;
	string input;
	cin >> r >> c;
	cin.get();
	vector<string> bin;
	vector<vector<string>> temp(r);

	for (int i = 0; i < r; i++)
	{
		getline(cin, input);
		bin.push_back(input);
		bin[i].erase(remove(bin[i].begin(), bin[i].end(), ' '), bin[i].end());
	}
	temp[0].push_back(bin[0]);

	for (int i = 1; i < r; i++)
	{
		temp[i].push_back(bin[i]);
		bitset<8> down(bin[i]);
		for (int j = 0; j < temp[i - 1].size(); j++)
		{
			bitset<8> up(temp[i - 1][j]);
			if (i == r - 1)
			{
				if (count(temp[i].begin(), temp[i].end(), (down ^ up).to_string()) == 0)
				{
					temp[i].push_back((down ^ up).to_string());
				}
			}
			else
			{
				temp[i].push_back((down ^ up).to_string());
			}
		}
	}

	cout << temp.back().size();
	return 0;
}