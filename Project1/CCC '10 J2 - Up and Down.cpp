#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int a, b, c, d, s;
	cin >> a >> b >> c >> d >> s;
	int player1 = 0, player2 = 0;

	vector<int> move1;
	vector<int> move2;
	for (int i = 0; i < a; i++)
		move1.push_back(1);
	for (int i = 0; i < c; i++)
		move2.push_back(1);
	for (int i = 0; i < b; i++)
		move1.push_back(-1);
	for (int i = 0; i < d; i++)
		move2.push_back(-1);

	for (int i = 0; i < s; i++)
	{
		player1 += move1[i % move1.size()];
		player2 += move2[i % move2.size()];
	}

	if (player1 > player2)
	{
		cout << "Nikky";
	}
	else if (player2 > player1)
	{
		cout << "Byron";
	}
	else
	{
		cout << "Tied";
	}

	return 0;
}