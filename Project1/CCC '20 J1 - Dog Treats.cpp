#include<iostream>
using namespace std;

int main()
{
	int s, m, l;
	cin >> s >> m >> l;

	if (s + 2 * m + 3 * l >= 10)
	{
		cout << "happy";
	}
	else
	{
		cout << "sad";
	}

	return 0;
}