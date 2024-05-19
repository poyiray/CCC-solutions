#include <iostream>
#include <map>
using namespace std;

int main()
{
	int c;
	char v, v2;
	map<char, int> A_B;
	A_B['A'] = 0;
	A_B['B'] = 0;
	while (cin >> c)
	{
		if (c == 7)
			break;

		if (c == 1)
		{
			int n;
			cin >> v >> n;
			A_B[v] = n;
		}
		else if (c == 2)
		{
			cin >> v;
			cout << A_B[v] << endl;
		}
		else if (c == 3)
		{
			cin >> v >> v2;
			A_B[v] = A_B[v] + A_B[v2];
		}
		else if (c == 4)
		{
			cin >> v >> v2;
			A_B[v] = A_B[v] * A_B[v2];
		}
		else if (c == 5)
		{
			cin >> v >> v2;
			A_B[v] = A_B[v] - A_B[v2];
		}
		else if (c == 6)
		{
			cin >> v >> v2;
			A_B[v] = A_B[v] / A_B[v2];
		}
	}

	return 0;
}