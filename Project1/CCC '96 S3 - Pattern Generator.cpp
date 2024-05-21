#include <bits/stdc++.h>
using namespace std;

//思路是每次先找到第一个10的位置，先将他们翻转
//然后再保留这个下标前面的字符串，然后再将这个位置之后的字符串翻转
//11100
//11010
//11001

//1.找到(10)
//11001
// ^
//然后保留前面的 1 翻转后面的01
//10110


int n, k, m;

//find the last 10
int fd(string s)
{
	for (int i = s.size() - 2; i >= 0; i--)
	{
		// 1100
		//   ^
		if (s.substr(i, 2) == "10") return i + 1;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> m;
	while (m--)
	{
		string s;
		cin >> n >> k;
		for (int i = 0; i < k; i++) s.push_back('1');
		for (int i = 0; i < n - k; i++) s.push_back('0');

		cout << "The bit patterns are\n" << s << '\n';
		int x;
		while ((x = fd(s)) != -1)
		{
			string first = s.substr(0, x - 1);
			string second = s.substr(x + 1, s.size() - first.size() - 2);
			reverse(second.begin(), second.end());
			s = first + "01" + second;
			cout << s << '\n';
		}
		if(m) cout << '\n';
	}
	

	return 0;
}