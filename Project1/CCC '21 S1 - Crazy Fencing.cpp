#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main()
{
	int n, input; double sum = 0; vector<double> side, width;

	cin >> n;
	for (int i = 0; i < n + 1; i++)
	{
		cin >> input;
		side.push_back(input);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		width.push_back(input);
	}

	for (int i = 0; i < n; i++)
	{
		sum += width[i] * (side[i] + side[i + 1]) / 2;
	}

	cout << fixed << setprecision(2) << sum;

	return 0;
}