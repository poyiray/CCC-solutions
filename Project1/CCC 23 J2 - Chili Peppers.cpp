#include<iostream>
#include<string>
using namespace std;

enum peppers
{
	Poblano = 1500,
	Mirasol = 6000,
	Serrano = 15500,
	Cayenne = 40000,
	Thai = 75000,
	Habanero = 125000
};

int main()
{
	int n = 0;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		string str = " ";
		cin >> str;
		if (str == "Poblano")
		{
			sum += 1500;
		}
		else if (str == "Mirasol")
		{
			sum += 6000;
		}
		else if (str == "Serrano")
		{
			sum += 15500;
		}
		else if (str == "Cayenne")
		{
			sum += 40000;
		}
		else if (str == "Thai")
		{
			sum += 75000;
		}
		else
		{
			sum += 125000;
		}
	}
	cout << sum;
	return 0;
}