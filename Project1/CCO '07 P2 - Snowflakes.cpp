#pragma GCC optimize(3,"Ofast","inline")
#include <bits/stdc++.h>
using namespace std;
char *p1, *p2, buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
inline int rd()
{
	int x = 0;
	char ch = nc();
	while (ch<'0' || ch>'9') ch = nc();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = nc();
	return x;
}
struct SF { int arr[6]; };
const int N = 1e5 + 10;
vector<SF> e[N];
int n;

int h(SF& sf)
{
	int s = 0, p = 1;
	for (int i = 0; i < 6; i++)
	{
		s += sf.arr[i];
		p = ((long long)p * sf.arr[i]) % 100003; // 将p暂时存储在longlong中
	}
	return (s + p) % 100003;
}

bool ck(SF& sf1, SF& sf2)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			int f = 0;
			for (int k = 0; k < 6; k++)
				if (sf1.arr[(i + k) % 6] != sf2.arr[(j + k) % 6]) { f = 1; break; }
			if (!f) return 1;
			f = 0;
			for (int k = 0; k < 6; k++)
				if (sf1.arr[(i + k) % 6] != sf2.arr[(j - k + 6) % 6]) { f = 1; break; }
			if (!f) return 1;
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	n = rd();
	for(int i = 1; i <= n; i++)
	{
		SF sf;
		for (int i = 0; i < 6; i++) sf.arr[i] = rd();
		int n = h(sf);
		for (auto& a : e[n])
		{
			if (ck(a, sf))
			{
				cout << "Twin snowflakes found.\n";
				return 0;
			}
		}
		e[n].push_back(sf);
	}
	cout << "No two snowflakes are alike.\n";
	return 0;
}