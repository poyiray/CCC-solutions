#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<vector<int>> m{{1,2},{3,4}};

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'H')
		{
			swap(m[0][0], m[1][0]);
			swap(m[0][1], m[1][1]);
		}
		else
		{
			swap(m[0][0], m[0][1]);
			swap(m[1][0], m[1][1]);
		}
	}

	for (auto arr : m)
	{
		for (auto val : arr)
		{
			cout << val << " ";
		}
		cout << endl;
	}

	return 0;
}