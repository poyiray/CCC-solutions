#include<iostream>
using namespace std;

int main()
{
	int total, a, b, c, time = 0;

	cin >> total >> a >> b >> c;

	while (total > 0)
	{
		total--;
		a++;
		time++;
		if (a % 35 == 0)
		{
			total += 30;
		}

		if (total == 0)
		{
			break;
		}
		
		total--;
		b++;
		time++;
		if (b % 100 == 0 && total >= 0)
		{
			total += 60;
		}
		if (total == 0)
		{
			break;
		}

		total--;
		c++;
		time++;
		if (c % 10 == 0 && total >= 0)
		{
			total += 9;
		}
	}

	cout << "Martha plays " << time << " times before going broke.";

	return 0;
}