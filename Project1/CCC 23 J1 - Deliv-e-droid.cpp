#include<iostream>
using namespace std;

int main()
{
	int g, l;
	cin >> g;
	cin >> l;
	if (g > l)
		cout << g * 50 - l * 10 + 500;
	else
		cout << g * 50 - l * 10;

	return 0;
}