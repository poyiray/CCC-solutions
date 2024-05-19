#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
string h[4] = { "Clubs", "Diamonds", "Hearts", "Spades" };
int main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	vector<vector<int>> c;int point = 0; int idx = 1, sum = 0; string s; c.resize(4);
	cin >> s;
	cout << "Cards Dealt              Points\n";
	for (int i = 0; i < 4; i++, idx++)
	{
		while (!(s[idx] == 'C' || s[idx] == 'D' || s[idx] == 'H' || s[idx] == 'S') && idx < s.length())
		{
			if (s[idx] == 'T')c[i].push_back(10);
			else if (s[idx] < 'A')c[i].push_back(s[idx] - '0');
			else
			{
				if (s[idx] == 'A')c[i].push_back(99);
				else if (s[idx] == 'K')c[i].push_back(98);
				else if (s[idx] == 'Q')c[i].push_back(97);
				else if (s[idx] == 'J')c[i].push_back(96);
			}
			idx++;
		}
	}
	for (int i = 0; i < c.size(); i++, point = 0)
	{
		cout << h[i] << " ";
		if (c[i].size() == 0)point += 3;
		else if (c[i].size() == 1)point += 2;
		else if (c[i].size() == 2)point += 1;
		for (int j = 0;j < c[i].size(); j++)
		{
			if (c[i][j] == 99)
			{
				cout << "A ";
				point += 4;
			}
			else if (c[i][j] == 98)
			{
				cout << "K ";
				point += 3;
			}
			else if (c[i][j] == 97)
			{
				cout << "Q ";
				point += 2;
			}
			else if (c[i][j] == 96)
			{
				cout << "J ";
				point++;
			}
			else
			{
				if (c[i][j] == 10)cout << "T ";
				else cout << c[i][j] << " ";
			}
		}
		cout << setw(30 - h[i].length() - (c[i].size() * 2)) << point << "\n";
		sum += point;
	}
	cout << setw(29) << "Total " << sum;
	return 0;
}