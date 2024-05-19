#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n, sum = 0;
	string y, t;
	cin >> n >> y >> t;

	for (int i = 0; i < n; i++)
	{
		if (y[i] == t[i] && y[i] == 'C') sum++;
	}

	cout << sum;

	return 0;
}