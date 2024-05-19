#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	
	int n = 1, input;
	while (cin >> input)
	{
		if (input == 0)
		{
			cout << "You Quit!";
			break;
		}
			

		if (n + input <= 100)
			n += input;

		if (n == 54)
			n = 19;
		else if (n == 90)
			n = 48;
		else if (n == 99)
			n = 77;
		else if (n == 9)
			n = 34;
		else if (n == 40)
			n = 64;
		else if (n == 67)
			n = 86;

		cout << "You are now on square " << n << endl;
		if (n == 100)
			cout << "You Win!";
	}
	

	return 0;
}