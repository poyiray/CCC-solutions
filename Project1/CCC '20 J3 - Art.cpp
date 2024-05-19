#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	char c;
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++)
		cin >> x[i] >> c >> y[i];

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	cout << x[0] - 1 << "," << y[0] - 1 << endl;
	cout << x.back() + 1 << "," << y.back() + 1 << endl;

	return 0;
}