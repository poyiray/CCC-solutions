#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int t, s, h;
	cin >> t >> s >> h;

	for (int i = 0; i < t; i++)
	{
		cout << setw(s + 1) << left << "*" << setw(s + 1) << left << "*" << right << "*" << endl;
	}
	for (int i = 0; i < s * 2 + 3; i++)
	{
		cout << "*";
	}
	cout << endl;

	for (int i = 0; i < h; i++)
	{
		cout << setw(s + 2) <<  right << "*";
		cout << endl;
	}

	return 0;
}