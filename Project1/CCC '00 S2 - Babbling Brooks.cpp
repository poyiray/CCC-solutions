#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	vector<long double> stream(100, 0);
	int n = 0, input;
	double temp, percent;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> stream[i];

	while (cin >> input)
	{
		if (input == 77)
			break;
		cin >> n;
		if (input == 99) //向左边流动的河流是直接分裂的，没有和左边的河流合并 (大坑)
		{
			cin >> percent;
			temp = stream[n] * (percent / 100);
			stream[n] -= temp;
			stream.insert(stream.begin() + n, temp);
		}
		else
		{
			stream[n + 1] += stream[n];
			stream.erase(stream.begin() + n);
		}
		stream.resize(100);
	}

	for (int i = 1; stream[i] != 0; i++)
		cout << round(stream[i]) << " ";

	return 0;
}