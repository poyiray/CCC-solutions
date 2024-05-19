#include <iostream>
#include <string>
using namespace std;

bool ispal(string s)
{
	for (int i = 0, j = s.size() - 1; i < j; i++, j--)
	{
		if (s[i] != s[j])
			return false;
	}
	return true;
}

int main()
{
	string s;
	cin >> s;
	int max = 0;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 1; j <= s.size(); j++)
		{
			string temp = s.substr(i, j);
			if (ispal(temp) && max < temp.size())
			{
				max = j;
			}
		}
	}
	cout << max << endl;

	return 0;
}