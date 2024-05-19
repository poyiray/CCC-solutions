#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T; cin >> T;
	while (T--)
	{
		string N; cin >> N;
		while (N.size() > 1)
		{
			int A = 0;
			for (char& c : N) A += c - '0';
			N = to_string(A);
		}
		cout << N << '\n';
	}

	return 0;
}