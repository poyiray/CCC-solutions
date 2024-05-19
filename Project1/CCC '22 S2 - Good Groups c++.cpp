#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int x, y;
	cin >> x;
	unordered_map<string, vector<string>> eme, fri;
	for (int i = 0; i < x; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if (!count(fri[s1].begin(), fri[s1].end(), s2))
		{
			fri[s1].push_back(s2);
			fri[s2].push_back(s1);
		}
	}
	cin >> y;
	for (int i = 0; i < y; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if (!count(eme[s1].begin(), eme[s1].end(), s2))
		{
			eme[s1].push_back(s2);
			eme[s2].push_back(s1);
		}
	}

	int g; cin >> g;
	int res = 0;
	vector<string> real_group(3);
	while(g--)
	{
		for(int i = 0; i < 3; i++)
			cin >> real_group[i];

		for (int i = 0; i < 3; i++)
		{
			if (!fri.count(real_group[i]))
				continue;
			vector<string>& temp = fri[real_group[i]];
			vector<string> current = fri[real_group[i]];
			for (auto& val : current)
			{
				if (!count(real_group.begin(), real_group.end(), val))
				{
					fri[val].erase(find(fri[val].begin(), fri[val].end(), real_group[i]));
					temp.erase(find(temp.begin(), temp.end(), val));
					res++;
				}
			}
		}

		for (int i = 0; i < 3; i++)
		{
			if (!eme.count(real_group[i]))
				continue;
			vector<string> current = eme[real_group[i]];
			vector<string>& temp = eme[real_group[i]];
			for (auto& val : current)
			{
				if (count(real_group.begin(), real_group.end(), val))
				{
					eme[val].erase(find(eme[val].begin(), eme[val].end(), real_group[i]));
					temp.erase(find(temp.begin(), temp.end(), val));
					res++;
				}
			}
		}
	}

	cout << res << endl;
	return 0;
}