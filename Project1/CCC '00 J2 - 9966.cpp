#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	int a, b, sum = 0, t = 0;
	string s;
	cin >> a >> b;

	for (int i = a; i <= b; i++)
	{
		s = to_string(i);
		if (s.length() % 2 == 0)
		{
			for (int j = s.length() / 2, z = s.length() / 2 - 1; j < s.length(); j++, z--)
			{
				if (((s[j] == '0' || s[j] == '1' || s[j] == '8') && s[z] == s[j]))
				{
					t++;
				}
				else if (s[j] == '9' || s[z] == '9' || s[j] == '6' || s[z] == '6')
				{
					if (s[j] == '9' && s[z] == '6')
					{
						t++;
					}
					else if (s[z] == '9' && s[j] == '6')
					{
						t++;
					}
				}
			}
			if (t * 2 == s.length())
			{
				sum++;
			}
		}
		else
		{
			if (s[s.length() / 2] == '0' || s[s.length() / 2] == '1' || s[s.length() / 2] == '8')
			{
				for (int j = s.length() / 2 + 1, z = s.length() / 2 - 1; j < s.length(); j++, z--)
				{
					if (((s[j] == '0' || s[j] == '1' || s[j] == '8') && s[z] == s[j]))
					{
						t++;
					}
					else if (s[j] == '9' || s[z] == '9' || s[j] == '6' || s[z] == '6')
					{
						if (s[j] == '9' && s[z] == '6')
						{
							t++;
						}
						else if (s[z] == '9' && s[j] == '6')
						{
							t++;
						}
					}
				}
				if (i < 10)
				{
					sum++;
				}
			}
			if (t * 2 + 1 == s.length() && i > 10)
			{
				sum++;
			}
		}

		t = 0;
	}

	cout << sum;

	return 0;
}