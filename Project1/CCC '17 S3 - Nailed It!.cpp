#include <bits/stdc++.h>
using namespace std;

char *p1, *p2, buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int rd()
{
	int x = 0;
	char ch = nc();
	while (ch < 48 || ch>57)
		ch = nc();
	while (ch >= 48 && ch <= 57)
		x = x * 10 + ch - 48, ch = nc();
	return x;
}

//由于N的数据量太大啦，就不能考虑使用暴力
//只能从长度下手
//记录每个木块不同长度的数量，帮且将他们组合成不同的木板
//假如高度是h 那么他们的组合为 1 + (h - 1), 2 + (h - 2)。。。 他们的组合一定是不一样的，这样也避免了重复的计算

const int L = 4010;
int length[L], fence[L], res, num, n, maxn;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd();
	for (int i = 1; i <= n; i++)
	{
		int x = rd();
		length[x]++;
		maxn = max(maxn, x);
	}

	for (int i = 1; i <= maxn; i++)
	{
		fence[i * 2] += length[i] / 2;
		for (int j = i + 1; j <= maxn; j++)
		{
			fence[i + j] += min(length[i], length[j]);
		}
	}

	for (int i = 1; i <= maxn * 2; i++)
	{
		if (fence[i] > res)
		{
			res = fence[i];
			num = 1;
		}
		else if (fence[i] == res) num++;
	}
	cout << res << " " << num;
	return 0;
}