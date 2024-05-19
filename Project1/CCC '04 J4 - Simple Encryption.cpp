#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	string s, word;
	cin >> s;
	cin.get();
	getline(cin, word);
	word.erase(remove_if(word.begin(), word.end(), [](char c) {return !isalpha(c);}), word.end());
	int row = ceil((double)word.size() / (double)s.size());
	vector<vector<char>> table(row);

	int idx = 0;
	for (int i = 0; i < word.size(); i++)
	{
		table[idx].push_back(word[i]);
		if ((i + 1) % s.size() == 0)
		{
			idx++;
		}
	}

	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			int shift = s[j] - 'A';
			if (table[i][j] + shift > 90)
			{
				table[i][j] = (table[i][j] + shift) % 90 + 64;
			}
			else
			{
				table[i][j] = table[i][j] + shift;
			}
			
		}
	}

	for (auto arr : table)
	{
		for (auto val : arr)
		{
			cout << val;
		}
	}


	return 0;
}