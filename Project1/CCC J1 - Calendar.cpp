#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	int day_of_week = 0, number_of_day = 0;
	cin >> day_of_week;
	cin >> number_of_day;
	
	cout << "Sun Mon Tue Wed Thr Fri Sat" << endl;

	for (int i = 0; i < day_of_week - 1; i++)
	{
		cout << "    ";
	}

	for (int i = 1; i < number_of_day + 1; i++)
	{
		cout << setw(3) << i;
		
		if ((day_of_week - 1 + i) % 7 == 0 || i == number_of_day)
		{
			cout << endl;
		}
		else
		{
			cout << " ";		
		}
	}

	return 0;
}