#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, cnt;
	string s = "";
	cin >> n;
	while (n--)
	{
		cin >> s;
		cnt = 0;
		for (int i = 0, c = s[0]; i < s.size() + 1; i++)
		{
			if (s[i] == c)
			{
				cnt++;
			}
			else
			{
				cout << cnt << " " << (char)c << " ";
				cnt = 1;
				c = s[i];
			}
		}
		cout << endl;
	}

	return 0;
}