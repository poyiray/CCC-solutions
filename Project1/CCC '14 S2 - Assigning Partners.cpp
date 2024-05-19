#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	map<string, string> group;
	string name[2][1000];
	int n; cin >> n;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			cin >> name[i][j];

	for (int i = 0; i < n; i++)
	{
		if ((group[name[0][i]] != name[1][i] || group[name[1][i]] != name[0][i]) && 
			group.count(name[0][i]) && group.count(name[1][i]))
		{
			cout << "bad";
			exit(0);
		}
		group[name[0][i]] = name[1][i];
		group[name[1][i]] = name[0][i];
	}
	cout << "good";
	return 0;
}