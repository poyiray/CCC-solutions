#include <bits/stdc++.h>
using namespace std;

// str 为代转字符串，n 为进制
int ntoi(string str, int n) {
	int ans = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			ans = ans * n + str[i] - '0';
		}
		else {
			ans = ans * n + str[i] - 'a' + 10;
			// 如果 字符串中是大写就 - ‘A’，小写就 - ‘a’
		}
	}
	return ans;
}

string iton(int num, int n) {
	string ans = "";
	do {
		int t = num % n;
		if (t >= 0 && t <= 9) {
			ans += t + '0';
		}
		else {
			ans += t - 10 + 'a';
		}
		num /= n;
	} while (num != 0);
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	int _ = 5;
	while (_--)
	{
		int p, a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		p = ntoi(to_string(a), b) * ntoi(to_string(c), d);
		cout << iton(p, e) << '\n';
	}

	return 0;
}