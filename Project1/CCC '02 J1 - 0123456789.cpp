#include<iostream>
#include<iomanip>
using namespace std;

/*

 * * *
	  *
	  *
	  *
 * * *
*
*
*
 * * *

 * * *
	  *
	  *
	  *
 * * *
      *
      *
      *
 * * *

*	  *
*	  *
*  	  *
 * * *
	  *
	  *
	  *

 * * *
*	  
*
*
 * * *
	  *
	  *
	  *
 * * *	 

*/

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int i;
	cin >> i;

	switch (i)
	{
	case 0:
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << setw(6) << left << "*" << right << "*" << "\n";
		cout << "\n";
		for (int i = 0; i < 3; i++) cout << setw(6) << left << "*" << right << "*" << "\n";
		cout << " * * *\n";
		break;
	case 1:
		cout << "\n";
		for (int i = 0; i < 3; i++) cout << setw(7) << "*" << "\n";
		cout << "\n";
		for (int i = 0; i < 3; i++) cout << setw(7) << "*" << "\n";
		cout << "\n";
		break;
	case 2:
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << setw(7) << "*" << "\n";
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << "*" << "\n";
		cout << " * * *\n";
		break;
	case 3:
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << setw(7) << "*" << "\n";
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << setw(7) << "*" << "\n";
		cout << " * * *\n";
		break;
	case 4:
		cout << "\n";
		for (int i = 0; i < 3; i++) cout << setw(6) << left << "*"  << right << "*" << "\n";
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << setw(7) << "*" << "\n";
		cout << "\n";
		break;
	case 5:
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << "*" << "\n";
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << setw(7) << "*" << "\n";
		cout << " * * *\n";
		break;
	case 6:
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << "*" << "\n";
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << setw(6) << left << "*" << right << "*" << "\n";
		cout << " * * *\n";
		break;
	case 7:
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << setw(7) << "*" << "\n";
		cout << "\n";
		for (int i = 0; i < 3; i++) cout << setw(7) << "*" << "\n";
		cout << "\n";
		break;
	case 8:
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << setw(6) << left << "*" << right << "*" << "\n";
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << setw(6) << left << "*" << right << "*" << "\n";
		cout << " * * *\n";
		break;
	case 9:
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << setw(6) << left << "*" << right << "*" << "\n";
		cout << " * * *\n";
		for (int i = 0; i < 3; i++) cout << setw(7) << "*" << "\n";
		cout << " * * *\n";
		break;
	default:
		break;
	}

	return 0;
}