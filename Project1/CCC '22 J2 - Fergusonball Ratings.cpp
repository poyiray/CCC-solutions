#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, input, sum = 0;
	cin >> n;
	vector<vector<int>> players;
	players.resize(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cin >> input;
			players[i].push_back(input);
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (players[i][0] * 5 - players[i][1] * 3 > 40)
		{
			sum++;
		}
	}

	cout << sum << (sum == n ? "+" : "");



	return 0;
}