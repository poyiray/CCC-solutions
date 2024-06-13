#include <bits/stdc++.h>
using namespace std;

#define double long double
struct node { double x, y; };
const int N = 1010;
node pos[N];
bool res[N];
int n;

double cul(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> pos[i].x >> pos[i].y;
	for (int i = 1; i <= n; i++)
	{
		pos[i].x *= 10000;
		pos[i].y *= 10000;
	}

	for (double i = 0; i <= 10000000; i += 100)
	{
		int idx = 0;
		double minn = INT_MAX;
		for (int j = 1; j <= n; j++)
		{
			double dis = cul(pos[j].x, pos[j].y, i, 0.0);
			if (dis < minn)
			{
				minn = dis;
				idx = j;
			}
		}
		res[idx] = 1;
	}

	for (int i = 1; i <= n; i++)
	{
		if (res[i])
		{
			cout << fixed << setprecision(2) << "The sheep at (" << pos[i].x / 10000 << ", " << pos[i].y / 10000 << ") might be eaten.\n";
		}
	}

	return 0;
}