#include<iostream>
#include<string>
using namespace std;

int main()
{
	int x, m;
	cin >> x;
	cin >> m;

	for (int i = 1; i < m; i++)
	{
		if ((x * i) % m == 1)
		{
			cout << i;
			return 0;
		}
	}

	cout << "No such integer exists.";
	//return 0;
}