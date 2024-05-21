#include <bits/stdc++.h>
using namespace std;

//如果一个数的 奇数位置上的数 - 偶数位置上的数 可以被 11 整除那么原本的数就可以被整除
int n;
string s;
vector<int> arr;


void dfs(int x, int num)
{
	if (x < 0) return;
	arr[x] -= num;
	if (arr[x] < 0) arr[x] = 10 + arr[x], dfs(x - 1, 1);
	else return;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	//freopen("out.txt", "w", stdout);
	cin >> n;
	while (n--)
	{
		cin >> s;
		for (auto& c : s) arr.push_back(c - '0');
		cout << s << '\n';
		bool p = 0, f = 1;
		int odd = 0, even = 0;
		p = 0, f = 1;
		for (auto& c : arr)
		{
			if (f) odd += c;
			else even += c;
			f = !f;
		}
		if ((odd - even) % 11 == 0) p = 1;

		while (arr.size() > 2)
		{
			int sub = arr.back(); arr.pop_back();
			dfs(arr.size() - 1, sub);
			if (arr.front() == 0) arr.erase(arr.begin());
			for (auto& c : arr) cout << c;
			cout << '\n';
		}
		if (p) cout << "The number " << s << " is divisible by 11.\n";
		else cout << "The number " << s << " is not divisible by 11.\n";
		if(n) cout << '\n';
		arr.clear();
	}

	return 0;
}