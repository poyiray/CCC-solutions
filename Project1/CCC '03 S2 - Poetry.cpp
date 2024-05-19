#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int n;
	string input;
	cin >> n;
	cin.get();

	vector<vector<string>> poem(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < 4; j++)
		{
			//cin.get(); 写错cin.get()发生的惨剧 (找了半天看不出来自己哪里错了，结果debug的时候发现vector里少了几个字才发现是这个倒霉玩意害的)
			getline(cin, input);
			poem[i].push_back(input);
		}

	vector<string> syllable(4, "");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = poem[i][j].size() - 1; k >= 0; k--)
			{
				if (poem[i][j][k] == ' ')
					break;
				poem[i][j][k] = tolower(poem[i][j][k]);
				syllable[j] += poem[i][j][k];
				if (poem[i][j][k] == 'a' || poem[i][j][k] == 'e'
					|| poem[i][j][k] == 'i' || poem[i][j][k] == 'o'
					|| poem[i][j][k] == 'u')
					break;
			}
		}
		if (syllable[0] == syllable[1] && syllable[0] == syllable[2]
			&& syllable[0] == syllable[3])
			cout << "perfect";
		else if (syllable[0] == syllable[1] && syllable[2] == syllable[3])
			cout << "even";
		else if (syllable[0] == syllable[2] && syllable[1] == syllable[3])
			cout << "cross";
		else if (syllable[0] == syllable[3] && syllable[1] == syllable[2])
			cout << "shell";
		else
			cout << "free";
		cout << endl;
		syllable.clear();
		syllable.resize(4, "");
	}

	return 0;
}