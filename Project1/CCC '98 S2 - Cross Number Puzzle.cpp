#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << R"(8128
153 370 371 407)";
	cout << 8128 << '\n' << 153 << 370 << 371 << 407;
	for (int i = 1000; i <= 9999; i++)
	{
		int sum = 0;
		for (int j = 1; j < i; j++)
			if (i % j == 0) sum += j;
		if (sum == i) cout << i << " ";
	}
	cout << '\n';
	for (int i = 100; i <= 999; i++)
	{
		int sum = 0; string t = to_string(i);
		for (auto c : t) sum += (c - '0') * (c - '0') * (c - '0');
		if (sum == i) cout << i << " ";
	}

	return 0;
}