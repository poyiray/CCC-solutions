#include <map>
#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
	map<double, double> data;
	int n; cin >> n;
	int time, speed;
	double res = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> time >> speed;
		data[time] = speed;
	}

	for (auto it = data.begin(); it != prev(data.end()); it++)
	{
		double temp = abs(it->second - next(it)->second) / abs(it->first - next(it)->first);
		if (temp > res) res = temp;
	}
	cout << fixed << setprecision(1) << res;

	return 0;
}