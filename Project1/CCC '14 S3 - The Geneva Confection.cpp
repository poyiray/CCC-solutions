#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t; cin >> t;
	int input;
	while (t--)
	{
		stack<int> m; //他麻痹，忘记初始化了焯！
		stack<int> b;
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			cin >> input;
			m.push(input);
		}

		int cnt = 1;
		while (m.size())
		{
			if (m.top() == cnt)
			{
				m.pop();
				cnt++;
			}
			else
			{
				while (b.size())
				{
					if (b.top() == cnt)
					{
						b.pop();
						cnt++;
					}
					else break;
				}
				b.push(m.top());
				m.pop();
			}
		}
		while (b.size())
		{
			if (b.top() == cnt)
			{
				b.pop();
				cnt++;
			}
			else break;
		}
		if (b.empty() && cnt - 1 == n) cout << "Y" << endl;
		else cout << "N" << endl;
	}

	return 0;
}