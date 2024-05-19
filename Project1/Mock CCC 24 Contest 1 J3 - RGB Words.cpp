#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long n, b = 0, r = 0;
	long total = 0;
	string w;
	cin >> n >> w;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		if (w[i] == 'G')
		{
			v.push_back(i);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = v[i] + 1; j < n; j++)
		{
			if (w[j] == 'B')
			{
				b++;
			}
			else if (w[j] == 'G')
			{
				break;
			}
		}

		for (int j = v[i] - 1; j >= 0; j--)
		{
			if (w[j] == 'R')
			{
				r++;
			}
			else if (w[j] == 'G')
			{
				break;
			}
		}

		total += r * b;
		r = b = 0;
	}


	cout << total;

	return 0;
}