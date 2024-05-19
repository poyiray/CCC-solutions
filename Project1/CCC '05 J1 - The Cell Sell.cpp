#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int d, e, w;
	double cost1, cost2;
	cin >> d >> e >> w;
	
	if(d - 100 >= 0) cost1 = (d - 100) * 0.25 + e * 0.15 + w * 0.2;
	else cost1 = e * 0.15 + w * 0.2;
	
	cout << "Plan A costs " << setprecision(2) << fixed << cost1 << endl;

	if (d - 250 >= 0) cost2 = (d - 250) * 0.45 + e * 0.35 + w * 0.25;
	else cost2 = e * 0.35 + w * 0.25;
	cout << "Plan B costs " << setprecision(2) << fixed << cost2 << endl;

	if (cost1 < cost2) cout << "Plan A is cheapest.";
	else if (cost2 < cost1) cout << "Plan B is cheapest.";
	else cout << "Plan A and B are the same price.";

	return 0;
}