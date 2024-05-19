#include <bits/stdc++.h>
using namespace std;

bool startWith(string str, string sub)
{
	if (sub.size() > str.size())
	{
		return false;
	}
	return str.substr(0, sub.size()) == sub;
}


bool endWith(string str, string sub)
{
	if (sub.size() > str.size())
	{
		return false;
	}
	return str.substr(str.size() - sub.size(), sub.size()) == sub;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int n;
	cin >> n;

	vector<vector<string>> word(n, vector<string>(3));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> word[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (startWith(word[i][0], word[i][1]) || startWith(word[i][0], word[i][2])
			|| startWith(word[i][1], word[i][0]) || startWith(word[i][1], word[i][2])
			|| startWith(word[i][2], word[i][1]) || startWith(word[i][2], word[i][0])
			|| endWith(word[i][0], word[i][1]) || endWith(word[i][0], word[i][2])
			|| endWith(word[i][1], word[i][2]) || endWith(word[i][1], word[i][0])
			|| endWith(word[i][2], word[i][1]) || endWith(word[i][2], word[i][0]))
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}

	return 0;
}