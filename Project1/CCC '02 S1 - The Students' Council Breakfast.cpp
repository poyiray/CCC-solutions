#include <bits/stdc++.h>
using namespace std;
int p = 0, g = 0, r = 0, o = 0, price = 0, t = 0, sum = 0;
vector<int> total;

void print(int a, int b, int c, int d)
{
	cout << "# of PINK is " << a << " # of GREEN is " << b << " # of RED is " << c << " # of ORANGE is " << d;
	cout << endl;
	total.push_back(a + b + c + d);
	sum++;
}

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	cin >> p >> g >> r >> o >> price;
	for (int i = 0; i * p <= price; i++)
		for (int j = 0; j * g + i * p <= price; j++)
			for (int k = 0; k * r + j * g + i * p <= price; k++)
				for (int l = 0; l * o + k * r + j * g + i * p <= price; l++)
					if (l * o + k * r + j * g + i * p == price)
						print(i, j, k, l);

	cout << "Total combinations is " << sum << ".\n";
	auto min = min_element(total.begin(), total.end());
	cout << "Minimum number of tickets to print is " << *min << ".";

	return 0;
}