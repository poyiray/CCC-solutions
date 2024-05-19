#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);

	unsigned __int64 n, k, sum = 0, marble = 0;
	vector<char> s;
	cin >> n >> k;
	char ch;
	for (unsigned __int64 i = 0; i < n; i++)
	{
		cin >> ch;
		s.push_back(ch);
	}

	vector<int> zeros;
	zeros.resize(n, 0);
	unsigned __int64 index = 0;

	for (unsigned __int64 i = 0; i < n - 1; i++)
	{
		if (s[i] == '1' && s[i + 1] == '1')
		{
			s[i] = '0';
		}
	}

	for (unsigned __int64 i = 0; i < n; i++)
	{
		if (s[i] == '1')
		{
			marble++;
		}
		else
		{
			zeros[marble]++;
		}
	}

	zeros.resize(marble);
	index = marble;

	if (s[0] == '0' && marble != 0)
	{
		zeros.erase(zeros.begin());
		index--;
	}

	sort(zeros.begin(), zeros.end());


	for (unsigned __int64 i = 0; i < index; i++)
	{
		if (zeros[i] != 0 && zeros[i] <= k)
		{
			k -= zeros[i];
			sum++;
		}
		else if (zeros[i] > k)
		{
			break;
		}
	}

	if (marble == 0 && k >= n)
	{
		marble++;
	}

	marble -= sum;
	cout << marble;

	return 0;
}
