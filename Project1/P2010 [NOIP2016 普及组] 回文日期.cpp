// #pragma GCC optimize(2)
#include <iostream>
#include <string>
using namespace std;

int y1_, y2, m1, m2, d1, d2, res;
string s;

int day[] = { 0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int check(int year)
{
	if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
		return 29; // Leap year
	else
		return 28; // Non-leap year
}

bool judge(string x)
{
	for (int i = 0; i < x.size() / 2; i++)
	{
		if (x[i] != x[x.size() - i - 1]) return false;
	}
	return true;
}

string itos(int x)
{
	string t = to_string(x);
	if (t.size() == 1) t.insert(0, "0");
	return t;
}

void solve()
{
	bool f = true;
	for (int i = y1_; i <= y2; i++)
	{
		day[2] = check(i);
		int month = (i == y2 ? m2 : 12);
		int sm = (f ? m1 : 1);
		for (int j = sm; j <= month; j++)
		{
			int d = (j == m2 && i == y2 ? d2 : day[j]);
			int sd = (f ? d1 : 1);
			for (int k = sd; k <= d; k++)
			{
				res += judge(itos(i) + itos(j) + itos(k));
			}
			f = false;
		}
	}
}

int main()
{
	//freopen("out.txt", "w", stdout);
	cin >> s;
	y1_ = stoi(s.substr(0, 4));
	m1 = stoi(s.substr(4, 2));
	d1 = stoi(s.substr(6, 2));
	cin >> s;
	y2 = stoi(s.substr(0, 4));
	m2 = stoi(s.substr(4, 2));
	d2 = stoi(s.substr(6, 2));

	solve();
	cout << res;

	return 0;
}