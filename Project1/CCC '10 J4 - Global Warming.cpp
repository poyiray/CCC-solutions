#include <bits/stdc++.h>
using namespace std;
vector<int> dif, arr;

void len()
{
	if (dif.size() == 0)
	{
		cout << 0 << endl;
		return;
	}

	vector<int> temp;
	int t = 0;
	for (int i = 0; i < dif.size(); i++)
	{
		t++;
		bool flag = false;
		temp.push_back(dif[i]);
		for (int j = i + 1, k = 0; j < dif.size(); j++, k++)
		{
			if (temp[k % temp.size()] != dif[j])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			cout << i + 1 << endl;
			return;
		}
	}
	cout << t + 1 << endl;
}

int main()
{
	int n, input;
	while (cin >> n)
	{
		if (n == 0)
			break;

		arr.resize(n); dif.resize(n - 1);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		for (int i = 0; i < arr.size() - 1; i++)
			dif[i] = arr[i] - arr[i + 1];

		len();
	}

	return 0;
}