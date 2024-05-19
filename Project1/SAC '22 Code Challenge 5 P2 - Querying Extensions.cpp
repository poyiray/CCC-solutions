#include <bits/stdc++.h>
using namespace std;

int n;  char m;
int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	if (m == 'l') if (!(n % 2)) cout << "right"; else cout << "left";
	if (m == 'r') if (!(n % 2)) cout << "left"; else cout << "right";

	return 0;
}