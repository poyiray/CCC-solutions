#include <bits/stdc++.h>
using namespace std;

struct node { double x, y; };
const int N = 1010;
node pos[N];
bool res[N];
int n;

double cul(double x1, double y1, double x2, double y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> pos[i].x >> pos[i].y;

	for (double i = 0.01; i <= 1000.0; i += 0.01)
	{
		int idx = 0;
		double minn = 9999999.0;
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
			cout << fixed << setprecision(2) << "The sheep at (" << pos[i].x << ", " << pos[i].y << ") might be eaten.\n";
		}
	}

	return 0;
}