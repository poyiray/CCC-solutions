#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> sub;
vector<string> master;

void find_sub(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		string temp = "";
		for (int j = i; j < s.size() + i; j++)
		{
			temp += s[j % s.size()];
		}
		sub.push_back(temp);
	}
}

void search_s(string s, int n)
{
	int cnt = 0;
	for (int i = 0; i <= s.size() - n; i++)
	{
		for (int j = 0; j < sub.size(); j++)
		{
			if (sub[j] == s.substr(i, n))
			{
				cout << "yes";
				exit(0);
			}
		}
	}
	cout << "no";
}

int main()
{
	string s, s2;
	cin >> s >> s2;

	find_sub(s2);
	search_s(s, s2.size());

	return 0;
}