#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n, k;
	double r1, r2;
	string arr;

	cin >> n >> r1 >> r2 >> k;
	cin >> arr;

	double expected_score = 0;
	double score = 0;
	for (int i = 0; i < n; i++)
	{
		expected_score = 1 / (((r2 - r1) / 400) * 10 + 1);
		if (arr[i] == 'W')
		{
			score = (1 - expected_score) * k;
		}
		else if (arr[i] == 'L')
		{
			score = (0 - expected_score) * k;
		}
		else
		{
			score = (0.5 - expected_score) * k;
		}
		score /= 2;

		if (arr[i] != 'T')
		{
			r1 += score;
			if (expected_score < 0)
			{
				r2 += score;
			}
			else
			{
				r2 -= score;
			}
		}
		cout << r1 << " " << r2 << endl;
	}

	return 0;
}