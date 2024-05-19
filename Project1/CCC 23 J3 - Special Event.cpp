#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void printVector(vector<string> &v)
{
	for (auto num : v)
	{
		cout << num << endl;
	}
}

void printVector(vector<int> &v)
{
	for (auto num : v)
	{
		cout << num << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> counter{ 0,0,0,0,0 };
	vector<string> schedule;

	for (int i = 0; i < n; i++)
	{
		string avail;
		cin >> avail;
		schedule.push_back(avail);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (schedule[i][j] == 'Y')
			{
				counter[j]++;
			}
		}
	}

	vector<int> result = counter;
	sort(counter.rbegin(), counter.rend());
	int max = counter[0];

	string output;

	for (int i = 0; i < 5; i++)
	{
		if (result[i] == max)
		{
			output += to_string(i + 1);
			output.append(",");
		}
	}

	output.erase(output.end() - 1);
	cout << output;

	return 0;
}