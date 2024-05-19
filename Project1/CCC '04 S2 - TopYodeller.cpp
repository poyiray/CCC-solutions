#include <bits/stdc++.h>
using namespace std;

struct player
{
	int num, socre = 0, rank = 1;
};

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	int n, k, input;
	cin >> n >> k;
	
	vector<player> l(n);

	for (int i = 0; i < n; i++)

	{
		l[i].num = i + 1;
	}

	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> input;
			l[j].socre += input;
		}
		vector<player> temp = l;
		sort(temp.begin(), temp.end(), [](player a, player b) {return a.socre > b.socre; });

		for (int i = n - 1; i >= 1; i--)
		{
			if (temp[i].socre == temp[i - 1].socre)
			{
				temp.erase(temp.begin() + i);
			}
		}

		for (auto& val : l)
		{
			for (int k = 0; k < temp.size(); k++)
			{
				if (val.socre == temp[k].socre)
				{
					if (val.rank < k + 1)
					{
						val.rank = k + 1;
					}
				}
			}
		}
	}

	sort(l.begin(), l.end(), [](player a, player b) {return a.socre > b.socre; });
	vector<player> temp;
	for (auto val : l)
	{
		if (val.socre == l[0].socre)
		{
			temp.push_back(val);
		}
	}

	sort(temp.begin(), temp.end(), [](player a, player b) {return a.num < b.num; });

	for (auto val : temp)
	{
		cout << "Yodeller " << val.num << " is the TopYodeller: score " << val.socre << ", worst rank " << val.rank << endl;
	}

	return 0;
}