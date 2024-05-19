#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	char in;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> in;
		in == 'A' ? a++ : b++;
	}
	if (a > b)
		cout << "A";
	else if (b > a)
		cout << "B";
	else
		cout << "Tie";

	return 0;
}