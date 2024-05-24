#include <bits/stdc++.h>
using namespace std;
//今年写过最傻逼的代码
int sx, sy, ex, ey, n, m, step, facing = 1;

void mov(bool x)
{
	if (x) //前进
	{
		if (facing == 1) ex += step; //上
		else if (facing == 2) ey -= step; //左
		else if (facing == 3) ex -= step; //下
		else if (facing == 4) ey += step; //右
	}
	else //改变朝向
	{
		if (facing == 1)
		{
			if (n == 2) facing = 4;
			else facing = 2;
		}
		else if (facing == 2)
		{
			if (n == 2) facing = 1;
			else facing = 3;
		}
		else if (facing == 3)
		{
			if (n == 2) facing = 2;
			else facing = 4;
		}
		else if (facing == 4)
		{
			if (n == 2) facing = 3;
			else facing = 1;
		}
	}
}

void back()
{
	int x = abs(sx - ex), y = abs(sy - ey);
	cout << "Distance is " << x + y << '\n';
	if (x + y == 0) return;
	if (ex == sx)
	{
		if (facing == 1)
		{
			if (ey < sy) cout << 2 << '\n';
			else cout << 3 << '\n';
		}
		else if (facing == 2)
		{
			if (ey < sy) cout << 2 << '\n' << 2 << '\n';
		}
		else if (facing == 3)
		{
			if (ey < sy) cout << 3 << '\n';
			else cout << 2 << '\n';
		}
		cout << 1 << '\n' << y << '\n';
	}
	else if (ey == sy)
	{
		if (facing == 2)
		{
			if (ex < sx) cout << 2 << '\n';
			else cout << 3 << '\n';
		}
		else if (facing == 3)
		{
			if (ex < sx) cout << 2 << '\n' << 2 << '\n';
		}
		else if (facing == 4)
		{
			if (ex < sx) cout << 3 << '\n';
			else cout << 2 << '\n';
		}
		cout << 1 << '\n' << x << '\n';
	}
	else if (ex < sx)
	{
		if (facing == 3)
		{
			if (ey < sy)
			{
				cout << 3 << '\n';
				cout << 1 << '\n' << y << '\n';
				cout << 3 << '\n';
				cout << 1 << '\n' << x << '\n';
			}
			else
			{
				cout << 2 << '\n';
				cout << 1 << '\n' << y << '\n';
				cout << 2 << '\n';
				cout << 1 << '\n' << x << '\n';
			}
		}
		else if (facing == 2)
		{
			if (ey < sy)
			{
				cout << 2 << '\n';
				cout << 1 << '\n' << x << '\n';
				cout << 2 << '\n';
				cout << 1 << '\n' << y << '\n';
			}
			else
			{
				cout << 1 << '\n' << y << '\n';
				cout << 2 << '\n';
				cout << 1 << '\n' << y << '\n';
			}
		}
		else if (facing == 1)
		{
			cout << 1 << '\n' << x << '\n';
			if (ey < sy)
				cout << 2 << '\n';
			else
				cout << 3 << '\n';
			cout << 1 << '\n' << y << '\n';
		}
		else if (facing == 4)
		{
			if (ey < sy)
			{
				cout << 1 << '\n' << y << '\n';
				cout << 3 << '\n';
				cout << 1 << '\n' << x << '\n';
			}
			else
			{
				cout << 3 << '\n';
				cout << 1 << '\n' << x << '\n';
				cout << 3 << '\n';
				cout << 1 << '\n' << y << '\n';
			}
		}
	}
	else if (ex > sx)
	{
		if (facing == 1)
		{
			if (ey < sy)
			{
				cout << 2 << '\n';
				cout << 1 << '\n' << y << '\n';
				cout << 2 << '\n';
				cout << 1 << '\n' << x << '\n';
			}
			else
			{
				cout << 3 << '\n';
				cout << 1 << '\n' << y << '\n';
				cout << 3 << '\n';
				cout << 1 << '\n' << x << '\n';
			}
		}
		else if (facing == 4)
		{
			if (ey < sy)
			{
				cout << 1 << '\n' << y << '\n';
				cout << 2 << '\n';
				cout << 1 << '\n' << x << '\n';
			}
			else
			{
				cout << 2 << '\n';
				cout << 1 << '\n' << x << '\n';
				cout << 2 << '\n';
				cout << 1 << '\n' << y << '\n';
			}
		}
		else if (facing == 2)
		{
			if (ey < sy)
			{
				cout << 3 << '\n';
				cout << 1 << '\n' << x << '\n';
				cout << 3 << '\n';
				cout << 1 << '\n' << y << '\n';
			}
			else
			{
				cout << 1 << '\n' << y << '\n';
				cout << 3 << '\n';
				cout << 1 << '\n' << x << '\n';
			}
			
		}
		else if (facing == 3)
		{
			if (ey < sy)
			{
				cout << 1 << '\n' << x << '\n';
				cout << 3 << '\n';
				cout << 1 << '\n' << y << '\n';
			}
			else
			{
				cout << 1 << '\n' << x << '\n';
				cout << 2 << '\n';
				cout << 1 << '\n' << y << '\n';
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> m;
	while (m--)
	{
		sx = sy = ex = ey = 0;
		facing = 1;
		while (cin >> n && n)
		{
			if (n == 1)
			{
				cin >> step;
				mov(1);
			}
			else
			{
				mov(0);
			}
		}
		back();
		if (m) cout << '\n';
	}

	return 0;
}