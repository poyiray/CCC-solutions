#include <bits/stdc++.h>
using namespace std;
int t;
vector<string> num;

char aph_num(char s)
{
	if (isalpha(s))
	{
		if (s >= 'A' && s <= 'C')
			return '2';
		else if (s >= 'D' && s <= 'F')
			return '3';
		else if (s >= 'G' && s <= 'I')
			return '4';
		else if (s >= 'J' && s <= 'L')
			return '5';
		else if (s >= 'M' && s <= 'O')
			return '6';
		else if (s >= 'P' && s <= 'S')
			return '7';
		else if (s >= 'T' && s <= 'V')
			return '8';
		else if (s >= 'W' && s <= 'Z')
			return '9';
	}
	else if (isalnum(s))
	{
		return s;
	}
	return ' ';
}

void convert(string s)
{
	string temp = "";
	for (int i = 0; i < s.size(); i++)
	{
		temp += aph_num(s[i]);
	}
	num.push_back(temp);
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	cin >> t;
	string s;
	for (int i = 0; i < t; i++)
	{
		cin >> s;
		convert(s);
	}

	for (int i = 0; i < t; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 6 || j == 3)
			{
				cout << "-";
			}
			if (num[i][j] == ' ')
				num[i].erase(j, 1);
			cout << num[i][j];
		}
		cout << endl;
	}

	return 0;
}