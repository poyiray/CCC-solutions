#include <iostream>
#include <string>
using namespace std;

int main()
{
	string city; int tmp;
	string res_city; int res_tmp = 1e9;
	while (cin >> city >> tmp)
	{
		if (tmp < res_tmp) res_city = city, res_tmp = tmp;
		if (city == "Waterloo") break;
	}
	cout << res_city;

	return 0;
}