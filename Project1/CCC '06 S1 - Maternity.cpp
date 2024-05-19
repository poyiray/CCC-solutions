#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

	string mother, father, child;
	int x, k = 0;
	cin >> mother >> father >> x;
	for (int i = 0; i < x; i++)
	{
		bool flag2 = false;
		cin >> child;
		for (int j = 0; j < child.size(); j++)
		{
			bool flag = false;
			for (; k < mother.size(); k++)
			{
				if (tolower(child[j]) != tolower(mother[k]))
					continue;

				if (isupper(child[j]))
				{
					if (child[j] != mother[k] && child[j] != father[k])
						flag = true;
					else
					{
						flag = false;
						break;
					}
				}
				else
				{
					if (child[j] == mother[k] && child[j] == father[k])
					{
						flag = false;
						break;
					}
					else
						flag = true;
				}
			}
			
			if (flag)
			{
				flag2 = true;
				cout << "Not their baby!" << endl;
				break;
			}
		}
		k = 0;
		if (!flag2)
			cout << "Possible baby." << endl;
	}
	return 0;
}