#include <bits/stdc++.h>
#include<math.h>
#include <iomanip>
using namespace std;

struct Sheep
{
	long double x[100];
	long double y[100];
};

struct Wolf
{
	long double y[100];
	long double x[100];
	long double distance[100];
};

int main()
{
	int num = 6;
	cin >> num;
	Sheep sheep;
	Wolf wolf[1005];
	int index[1005] = { 0 };
	int time = 0;
	for (int i = 0; i < num; i++)
	{
		cin >> sheep.x[i] >> sheep.y[i];
	}

	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < num; j++)
		{
			wolf[i].x[j] = sheep.x[j];
			wolf[i].y[j] = sheep.y[j];
			wolf[i].distance[j] = (sqrt(pow(i - sheep.x[j], 2) + pow(0 - sheep.y[j], 2)));
		}
	}


	for (int i = 0; i < 1000; i++)
	{
		float temp = wolf[i].distance[0];
		index[time] = 0;
		for (int j = 1; j < num; j++)
		{

			if (wolf[i].distance[j] < temp)
			{
				index[time] = j;
				temp = wolf[i].distance[j];
			}

		}

		time++;

	}

	for (int i = 0; i < 1000; i++)
	{
		for (int j = i; j < 1000; j++)
		{
			if (index[i] == index[j + 1])
			{
				index[j + 1] = -1;
			}
		}
	}

	for (int i = 0; i < 1000; i++)
	{
		if (index[i] != -1)
		{
			cout << fixed << setprecision(2) << "The sheep at (" << noshowpoint << sheep.x[index[i]] << ", " << noshowpoint << sheep.y[index[i]] << ") might be eaten." << endl;
		}
	}

	return 0;
}