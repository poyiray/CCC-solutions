#include <bits/stdc++.h>
using namespace std;

const int N = 110;
string A[N], B[N];
int n, a, b;

bool cmp(string s1, string s2)
{
	if (s1 == "rock" && s2 == "scissors" || s1 == "scissors" && s2 == "paper" || s1 == "paper" && s2 == "rock") return true;
	return false;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < n; i++) cin >> B[i];
	for (int i = 0; i < n; i++)
	{
		if (cmp(A[i], B[i])) a++;
		else if (cmp(B[i], A[i])) b++;
	}
	cout << a << " " << b;

	return 0;
}