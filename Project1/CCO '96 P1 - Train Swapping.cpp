#include <bits/stdc++.h>
using namespace std;

const int N = 55;
int n, l;
int arr[N];

int solve()
{
	int res = 0;
	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < l - i - 1; j++)
		{
			if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]), res++;
		}
	}
	return res;
}

int main()
{
	cin >> n;
	while (n--)
	{
		cin >> l;
		for (int i = 0; i < l; i++) cin >> arr[i];
		cout << "Optimal train swapping takes " << solve() << " swaps.\n";
	}

	return 0;
}