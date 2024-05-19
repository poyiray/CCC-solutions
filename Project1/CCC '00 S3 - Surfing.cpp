#include <regex>
#include <string>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

string u, v;
map<string, vector<string>> to;
map<string, bool> st;
bool flag = false;
void dfs(string root)
{
	if (root == v) flag = true;
	if (flag) return;
	if (!to[root].size()) return;
	for (int i = 0; i < to[root].size(); i++)
	{
		if (st[to[root][i]]) continue;
		st[to[root][i]] = true;
		dfs(to[root][i]);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; cin >> n;
	while (n--)
	{
		string root; cin >> root;
		st[root] = false;
		string text, input;
		to[root];
		cin.get();
		while (getline(cin, input))
		{
			if (input == "</HTML>") break;
			text += input;
		}
		smatch link;
		string::const_iterator searchStart(text.cbegin());
		while (regex_search(searchStart, text.cend(), link, regex("<A HREF=\"(.*?)\">")))
		{
			cout << "Link from " << root << " to " << link[1] << endl;
			st[link[1].str()] = false;
			to[root].push_back(link[1].str());
			searchStart = link.suffix().first;
		}
	}
	
	while (cin >> u >> v)
	{
		flag = false;
		if (u == "The" && v == "End") break;
		dfs(u);
		if (flag) cout << "Can surf from " << u << " to " << v << "." << endl;
		else cout << "Can't surf from " << u << " to " << v << "." << endl;
		for (auto& val : st)
		{
			val.second = false;
		}
	}

	return 0;
}