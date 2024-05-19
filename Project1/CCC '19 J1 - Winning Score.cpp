#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	int s[2], a, b, c;
	
	for (int i = 0; i < 2; i++)
	{
		cin >> a >> b >> c;
		s[i] = a * 3 + b * 2 + c;
	}

	if (s[0] > s[1])
	{
		cout << "A";
	}
	else if (s[0] < s[1])
	{
		cout << "B";
	}
	else
	{
		cout << "T";
	}

	return 0;
}