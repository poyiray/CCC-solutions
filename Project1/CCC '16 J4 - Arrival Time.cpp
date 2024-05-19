#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	string s;
	cin >> s;
	int time = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
	for (int dis = 120; dis > 0; dis -= 10)
	{
		if ((time >= 420 && time < 600) || (time >= 900 && time < 1140))
			time += 20;
		else
			time += 10;
	}

	time %= 1440;
	cout << setfill('0') << setw(2) << time / 60 << ":" << setw(2) << time % 60;

	return 0;
}