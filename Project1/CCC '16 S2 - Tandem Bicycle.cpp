#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	int c, n;
	cin >> c >> n;
	vector<int> arr1(n), arr2(n), temp(n * 2);
	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
		temp[i] = arr1[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> arr2[i];
		temp[i + n] = arr2[i];
	}
	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());
	sort(temp.begin(), temp.end());
	if (c == 2)
		cout << accumulate(temp.begin() + n, temp.end(), 0);
	else
	{
		int total = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr1[i] >= arr2[i])
				total += arr1[i];
			else
				total += arr2[i];
		}
		cout << total;
	}

	return 0;
}