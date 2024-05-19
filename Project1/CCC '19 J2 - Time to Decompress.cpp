#include <iostream>
using namespace std;

int main()
{
	int n, t;
	char c;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> t >> c;
		while (t--)
		{
			cout << c;
		}
		cout << endl;
	}

	return 0;
}