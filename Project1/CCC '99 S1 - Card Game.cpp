#include <bits/stdc++.h>
using namespace std;

const int N = 100;
int res1, res2;
string card[N];

int check(int i, string s)
{
	int cnt = 0;
	if (s == "jack") cnt = 1;
	else if (s == "queen") cnt = 2;
	else if (s == "king") cnt = 3;
	else if (s == "ace") cnt = 4;
	else return 0;
	if (i + cnt > 52) return 0;
	int idx = i + cnt;
	for (++i; i <= idx; i++)
	{
		if (card[i] == "jack" || card[i] == "queen" || card[i] == "ace" || card[i] == "king") cnt = 0;
	}
	return cnt;
}

int main()
{
	for (int i = 1; i <= 52; i++) cin >> card[i];
	for (int i = 1; i <= 52; i++)
	{
		string s = card[i];
		int score = check(i, s);
		if (!score) continue;
		if (i % 2 != 0)
		{
			res1 += score;
			cout << "Player A scores " << score << " point(s).\n";
		}
		else 
		{
			res2 += score;
			cout << "Player B scores " << score << " point(s).\n";
		}
	}

	cout << "Player A: " << res1 << " point(s).\n";
	cout << "Player B: " << res2 << " point(s).\n";

	return 0;
}